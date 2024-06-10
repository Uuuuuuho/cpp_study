#include <iostream>

struct Shape
{
  virtual void Draw() = 0;
};
struct Rect : public Shape
{
  void Draw() override {std::cout << "React Draw" << std::endl;}
};
struct Circle : public Shape
{
  void Draw() override {std::cout << "Circle Draw" << std::endl;}
};

int main()
{
  void(Shape::*f)() = &Shape::Draw;

  printf("%p\n", f);

  Rect r; (r.*f)();
  Circle c; (c.*f)();
}