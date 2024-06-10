#include <iostream>

class Marine {
  int hp;
  int coord_x, coord_y;
  int damage;
  bool is_dead;

public:
  Marine();             // default constructor
  Marine(int x, int y); // marine constructor at the coordinate of (x,y)

  int attack();
  void be_attacked(int damage_earn);
  void move(int x, int y);

  void show_status();
};

Marine::Marine(){
  hp = 50;
  coord_x = coord_y = 0;
  damage = 5;
  is_dead = false;
}
Marine::Marine(int x, int y){
  coord_x = x;
  coord_y = y;
  hp = 50;
  damage = 5;
  is_dead = false;
}
void Marine::move(int x, int y){
  coord_x = x;
  coord_y = y;
}
int Marine::attack(){return damage;}
void Marine::be_attacked(int damage_earn){
  hp -= damage_earn;
  if(hp<=0) is_dead = true;
}
void Marine::show_status(){
  std::cout << " *** Marine *** " << std::endl;
  std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) "
            << std::endl;
  std::cout << " HP : " << hp << std::endl;
}

int main(){
  Marine m1(2,3);
  Marine m2(3,5);

  m1.show_status();
  m2.show_status();

  std::cout << std::endl << "m1 attacked m2! " << std::endl;
  m2.be_attacked(m1.attack());

  m1.show_status();
  m2.show_status();
}
