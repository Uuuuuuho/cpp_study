#include <iostream>
#include <cstring>

class MyString{
  char* string_content; // 문자열 데이터를 가리키는 포인터
  int string_length;    // 문자열 길이
  int memory_capacity;  // 문자열 용량
public:
  // 문자 하다로 생성
  MyString(char c);
  // 문자열로부터 생성
  MyString(const char* str);
  // 복사 생성자
  MyString(const MyString& str);
  // capaciy만틈 미리 할당함.
  // explicit 키워드에 주목
  explicit MyString(int capaciy);
  ~MyString();
  int length() const;
  void print();
};

MyString::MyString(char c)
{
  string_content = new char[1];
  string_content[0] = c;
  string_length = 1;
}
MyString::MyString(const char* str)
{
  string_length = strlen(str);
  string_content = new char[string_length];

  for(int i = 0; i != string_length; i++) string_content[i] = str[i];
}
MyString::MyString(const MyString& str)
{
  string_length = str.string_length;
  string_content = new char[string_length];

  for(int i = 0; i != string_length; i++) string_content[i] = str.string_content[i];
}

MyString::MyString(int capaciy)
{
  string_content = new char[capaciy];
  string_length = 0;
  memory_capacity = capaciy;
}

MyString::~MyString() { delete[] string_content; }
int MyString::length() const { return string_length; }
void MyString::print() 
{ 
  for(int i = 0; i != string_length; i++) std::cout << string_content[i]; 
  std::cout << std::endl;
}

void DoSomethingWithString(MyString s){
  // Do Something...
}

int main()
{
  DoSomethingWithString(3); // ????
  MyString s(5);    // accept
  MyString s1 = 5;  // compiler error
}