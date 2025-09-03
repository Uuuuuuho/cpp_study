#include <atomic>

class RefCountBase
{
protected:
  // Use atomic counter for thread-safety: multiple threads can call
  // addRef()/release() concurrently without data races.
  // mutable allows these methods to be const so callers holding a const
  // pointer can still increment/decrement the counter.
  mutable std::atomic<int> refcnt{0};
public:
  // Increment with relaxed ordering: we only need an atomic increment,
  // synchronization is provided by the corresponding release logic.
  void addRef() const { refcnt.fetch_add(1,std::memory_order_relaxed);} 
};
template<typename T> class RefCount : public RefCountBase
{
public:
  void release() const{
    // Decrement and check if this was the last reference. We use
    // acquire-release ordering to synchronize with other threads that
    // performed addRef() (relaxed increment) and to ensure that, when
    // we observe the last owner, subsequent operations see a consistent
    // state before deletion.
    int ret = refcnt.fetch_sub(1, std::memory_order_acq_rel);
    if(ret==1) {
      // CRTP trick: delete the complete object without virtual dtor.
      // Safety requirements:
      // - T must be the most-derived type (i.e. class T : RefCount<T>),
      //   and must not be further derived.
      // - object must have been allocated with new.
      delete static_cast<const T*>(this);
    }
  }
};
class Truck : public RefCount<Truck>{};
int main()
{
  Truck* p1 = new Truck;
  p1->addRef();
  p1->release();
}
