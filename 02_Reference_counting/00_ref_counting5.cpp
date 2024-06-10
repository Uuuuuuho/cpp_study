#include <iostream>

// const member function
template<typename T> class RefCount
{
  mutable int refcnt = 0; // 상수멤버 함수에서도 수정가능한 멤버
public:
  void addRef() const {++refcnt;}
  void release() const{if(--refcnt==0) delete static_cast<const T*>(this);}
protected:
  ~RefCount() {std::cout << "~RefCount" << std::endl;}
};
class Truck : public RefCount<Truck>
{
public:
  ~Truck(){std::cout << "~Truck()" << std::endl;}
};

int main(){
  const Truck *p1 = new Truck;
  p1->addRef();
  p1->release();
}