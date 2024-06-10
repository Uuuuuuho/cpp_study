#include <string>

class Vector
{
private:
  /* data */
  std::string* data;
  int capacity;
  int length;

public:
  // cannot change data type => template data type could be used
  Vector(int n = 1) : data(new std::string[n]), capacity(n), length(0){}

  // 맨 뒤에 새로운 원소를 추가한다.
  void push_back(std::string s){
    if (capacity <= length){
      std::string* temp = new std::string[capacity*2];
      for(int i = 0; i < length; i++) temp[i] = data[i];
      delete[] data;
      data = temp;
      capacity *= 2;
    }    

    data[length] = s;
    length++;
  }

  // 임의의 위치의 원소에 접근
  std::string operator[](int i){ return data[i]; }
  // x번째 위치한 원소를 제거한다.
  void remove(int x){
    for(int i = x+1; i < length; i++) data[i-1] = data[i];
    length--;
  }
  // 현재 벡터 크기를 구한다.
  int size(){ return length; }
  ~Vector() { if(data) delete[] data; }
};