#include <iostream>

class Animal{   // this is abstract class
public:
  Animal() {}
  virtual ~Animal(){}
  virtual void speak() = 0; // meaning pure virtual function
};
class Dog : public Animal
{
public:
  Dog() : Animal(){};
  void speak() override {std::cout << "walwal" << std::endl;}
};
class Cat : public Animal
{
public:
  Cat() : Animal(){}
  void speak() override {std::cout << "yaong yaong" << std::endl;}
};

int main()
{
  Animal* dog = new Dog();
  Animal* cat = new Cat();

  dog->speak();
  cat->speak();
}
