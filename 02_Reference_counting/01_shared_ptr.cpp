#include <iostream>
#include <memory>

class Truck{};

int main(){
  std::shared_ptr<Truck> sp1(new Truck);
  // shared pointer를 사용하면 인스턴스들이 가리키는 
  // 객체는 동일하게 유지되니까 메모리 효율성이 좋아지게 됩니다.
  std::shared_ptr<Truck> sp2 = sp1;

  Truck* p1 = new Truck;
  std::shared_ptr<Truck> sp3(p1);
  std::shared_ptr<Truck> sp4(p1);
}