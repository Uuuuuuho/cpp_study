#include <iostream>
#include <string.h>

class Marine {
  int hp;
  int coord_x, coord_y;
  int damage;
  bool is_dead;
  char* name;

public:
  Marine();             // default constructor
  Marine(int x, int y); // marine constructor at the coordinate of (x,y)
  Marine(int x, int y, const char* marine_name);
  ~Marine();

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
Marine::Marine(int x, int y, const char* marine_name){
  name = new char[strlen(marine_name) + 1];
  strcpy(name, marine_name);

  coord_x = x;
  coord_y = y;
  hp = 50;
  damage = 5;
  is_dead = false;
}
Marine::~Marine(){
  std::cout << name << " 의 소멸자 호출 ! " << std::endl;
  if(name != NULL){
    delete[] name;
  }
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
  Marine* marine[100];

  marine[0] = new Marine(2,3,"marine 2");
  marine[1] = new Marine(3,5,"marine 1");
  marine[0]->show_status();
  marine[1]->show_status();
  std::cout << std::endl << "m1 attacked m2! " << std::endl;

  marine[0]->be_attacked(marine[1]->attack());

  marine[0]->show_status();
  marine[1]->show_status();

  delete marine[0];
  delete marine[1];
}
