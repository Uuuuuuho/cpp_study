#include <iostream>
#include <cstring>

class MyString{
  char* string_content; // 문자열 데이터를 가리키는 포인터
  int string_length;    // 문자열 길이
  int memory_capacity;  // 현재 할당된 길이
public:
  // 문자 하나로 생성
  MyString(char c);
  // 문자열로부터 생성
  MyString(const char* str);
  // 복사 생성자
  MyString(const MyString& str);
  ~MyString();

  int length() const;
  void print();
  int capacity() { return memory_capacity;}
  void reserve(int size);
  char at(int i) const;

  MyString& assign(const MyString& str);
  MyString& assign(const char* str);
  MyString& insert(int loc, const MyString& str);
  MyString& insert(int loc, const char* str);
  MyString& insert(int loc, char c);
  MyString& erase(int loc, int num);

};

MyString::MyString(char c)
{
  string_content = new char[1];
  string_content[0] = c;
  string_length = 1;
  memory_capacity = 1;
}
MyString::MyString(const char* str)
{
  string_length = strlen(str);
  memory_capacity = string_length;
  string_content = new char[string_length];

  for(int i = 0; i != string_length; i++) string_content[i] = str[i];
}
MyString::MyString(const MyString& str)
{
  string_length = str.string_length;
  memory_capacity = str.memory_capacity;
  string_content = new char[string_length];

  for(int i = 0; i != string_length; i++) string_content[i] = str.string_content[i];
}
MyString::~MyString() { delete[] string_content; }
int MyString::length() const { return string_length; }
void MyString::print() 
{ 
  for(int i = 0; i != string_length; i++) std::cout << string_content[i]; 
  std::cout << std::endl;
}
MyString& MyString::assign(const MyString& str)
{
  if(str.string_length > memory_capacity){
    // 메모리 재할당
    delete[] string_content;
    string_content = new char[str.string_length];
  }
  for(int i = 0; i != str.string_length; i++) string_content[i] = str.string_content[i];
  string_length = str.string_length;
  return *this;
}
MyString& MyString::assign(const char* str)
{
  int str_length = strlen(str);
  if(str_length > memory_capacity){
    delete[] string_content;
    string_content = new char[str_length];
  }
  for (int i = 0; i!= str_length; i++) string_content[i] = str[i];
  string_length = str_length;
  return *this;  
}

MyString& MyString::insert(int loc, const MyString& str)
{
  // 이는 i의 위치 바로 앞에 문자를 삽입하게 된다. 예를들어서 
  // abc라는 문자열에 insert(1, "d")를 하게 된다면 adbc가 된다.

  // 범위를 벗어나는 입력에 대해서는 삽입을 수행하지 않는다.
  if(loc < 0 || loc > string_length) return *this;

  if(string_length + str.string_length > memory_capacity){
    // 이제 새롭게 동적으로 할당을 해야한다.
    memory_capacity = string_length + str.string_length;

    char* prev_string_content = string_content;
    string_content = new char[memory_capacity];

    // 일단 insert 되는 부분 직전까지의 내용을 복사한다.
    int i = 0;
    for(i = 0; i < loc; i++) string_content[i] = prev_string_content[i];
    for(int j = 0; j != str.string_length; j++) string_content[i+j] = str.string_content[j];
    for(; i < string_length; i++) string_content[str.string_length + i] = prev_string_content[i];

    delete[] prev_string_content;

    string_length = string_length + str.string_length;
    return *this;
  }

  // 만일 초과하지 않는 경우, 굳이 동적할당을 할 피룡가 없게 된다.
  // 효율적으로 insert하기 위해, 밀리는 부분을 먼저 뒤로 밀어버린다.

  for(int i = string_length-1; i >= loc; i--){
    // 뒤로 밀기. 이 때 원래의 문자열 데이터가 사라지지 않게 함.
    string_content[i + str.string_length] = string_content[i];
  }
  // 그리고 insert 되는 문자 다시 집어넣기
  for(int i = 0; i < str.string_length; i++) string_content[i + loc] = str.string_content[i];
  string_length = string_length + str.string_length;
  return *this;
}

MyString& MyString::insert(int loc, const char* str)
{
  MyString temp(str);
  return insert(loc, temp);
}

MyString& MyString::insert(int loc, char c)
{
  MyString temp(c);
  return insert(loc, temp);
}

MyString& MyString::erase(int loc, int num)
{
  // loc 앞부터 시작해서 num 문자를 지운다.
  if(num < 0 || loc < 0 || loc > string_length) return *this;

  // 지운다는 것은 단순히 뒤의 문자들을 앞으로 끌고 온다고
  // 생각하면 됨.
  for(int i = loc + num; i < string_length; i++) string_content[i-num] = string_content[i];
  string_length -= num;
  return *this;
}

void MyString::reserve(int size)
{
  if (size > memory_capacity){
    char * prev_string_content = string_content;

    string_content = new char[size];
    memory_capacity = size;
    for(int i = 0; i != string_length; i++) string_content[i] = prev_string_content[i];
    delete[] prev_string_content;
  }
}
char MyString::at(int i) const
{
  if(i >= string_length || i < 0) return NULL;
  else                            return string_content[i]; 
}

int main()
{
  MyString str1("very long string");
  // MyString str2("ttt");
  MyString str2("some string inserted between");
  str1.reserve(30);

  std::cout << "Capacity : " << str1.capacity() << std::endl;
  std::cout << "String length : " << str1.length() << std::endl;
  str1.print();

  str1.insert(5, str2);
  str1.print();
}