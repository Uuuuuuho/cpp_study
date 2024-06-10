#include <iostream>
#include <memory>

class Truck{};

int main(){
  std::shared_ptr<Truck> sp1(new Truck);
  std::shared_ptr<Truck> sp2 = sp1;

  Truck* p1 = new Truck;
  std::shared_ptr<Truck> sp3(p1);
  std::shared_ptr<Truck> sp4(p1);
}