#include <iostream>
#include <string>

template <typename T>
class Vector
{
private:
  /* data */
  T* data;
  int capacity;
  int length;

public:
  // cannot change data type => template data type could be used
  Vector(int n = 1) : data(new T[n]), capacity(n), length(0){}

  // 맨 뒤에 새로운 원소를 추가한다.
  void push_back(T s){
    if (capacity <= length){
      T* temp = new T[capacity*2];
      for(int i = 0; i < length; i++) temp[i] = data[i];
      delete[] data;
      data = temp;
      capacity *= 2;
    }    

    data[length] = s;
    length++;
  }

  // 임의의 위치의 원소에 접근
  T operator[](int i){ return data[i]; }
  // x번째 위치한 원소를 제거한다.
  void remove(int x){
    for(int i = x+1; i < length; i++) data[i-1] = data[i];
    length--;
  }
  // 현재 벡터 크기를 구한다.
  int size(){ return length; }
  ~Vector() { if(data) delete[] data; }
};

int main()
{
  // int를 보관하는 벡터를 만든다.
  Vector<int> int_vec;
  int_vec.push_back(3);
  int_vec.push_back(2);

  std::cout << "=========== int vector =============" << std::endl;
  std::cout << "first element : " << int_vec[0] << std::endl;
  std::cout << "second element : " << int_vec[1] << std::endl;

  Vector<std::string> str_vec;
  str_vec.push_back("hello");
  str_vec.push_back("world");
  std::cout << "=========== str vector =============" << std::endl;
  std::cout << "first element : " << str_vec[0] << std::endl;
  std::cout << "second element : " << str_vec[1] << std::endl;
}