#include <iostream>

template<typename T> class RefCount
{
  int refcnt = 0;
public:
  void addRef(){++refcnt;}
  // CRTP (Curiously Recurring Template Pattern)
  // virtual function의 오버헤드를 제거하기 위함.
  void release(){if(--refcnt==0) delete static_cast<T*>(this);}
protected:
  ~RefCount() {std::cout << "~RefCount" << std::endl;}
};
class Truck : public RefCount<Truck>
{
public:
  ~Truck(){std::cout << "~Truck()" << std::endl;}
};

int main(){
  Truck *p1 = new Truck;
  p1->addRef();
  p1->release();
}