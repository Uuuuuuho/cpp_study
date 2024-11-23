#include <iostream>

/* 
 * Template을 위해 "template"의 인자로 "typename"을 사용하는데,
 * 대신에 "class"도 사용 가능함. 사실 예전의 C++에서는 "class"를
 * 사용했으나 타입으로 class가 와야할 것 같은 어감때문에 "typename"
 * 으로 변경됨.
 */

template <typename T>
class Vector {
    T* data;
    int capacity;
    int length;

public:
    // 생성자
    Vector(int n = 1) : data(new T[n]), capacity(n), length(0) {}

    // 맨 뒤에 새로운 원소를 추가한다.
    void push_back(T s) {
        if (capacity <= length) {
            T* tmp = new T[capacity * 2];
            for (int i = 0; i < length; i++) {
                tmp[i] = data[i];
            }
            delete[] data;
            data = tmp;
            capacity *= 2;
        }

        data[length] = s;
        length++;
    }

    // 임의의 위치의 원소를 접근한다.
    T operator[](int idx) { return data[idx]; }

    // x 번째 원소를 제거한다.
    void remove(int idx) {
        for(int i = idx; i < length; i++) {
            data[i - 1] = data[i];
        }
        length--;
    }

    // 현재 벡터의 크기를 구한다.
    int size() { return length; }

    ~Vector() {
        if(data) {
            delete[] data;
        }
    }
};

// Template instantiation: 클래스 템플릿에 인자를 전달해서 실제 코드를 생성하는 것.
// Vector<bool> bool_vec;

/* Template specialization
 * 위의 경우와 같이 bool 데이터 타입은 1-bit만 필요한데 1-Byte를
 * 사용하게 되면 메모리 낭비가 발생함. 따라서 인자로 받아오는 "typename"에
 * 따라 템플릿 함수의 동작을 다르게 하려면 template을 사용하면 됨.
 */

template <typename A, typename B, typename C>
class test {};
// A가 int이고, C가 double일때 따로 처리를 원하는 경우
template <typename B>
class test<int, B, double> {};
// B조차도 specialization을 적용하고자 하는 경우
template <>
class test<int, int, double> {};

// 전달하는 템플릿 인자가 없어도 specialization을 적용할 경우
template <>
class Vector<bool> {
    // ... 원하는 코드
    uint* data;
    int capacity;
    int length;

public:
    typedef bool value_type;

    // 생성자
    Vector(int n = 1)
        : data(new uint [n / 32 + 1]), capacity(n / 32 + 1), length(0) {
            for(int i = 0; i < capacity; i++) {
                data[i] = 0;
            }
        }

    // 맨 뒤에 새로운 원소를 추가한다.
    void push_back(bool s) {
        if (capacity * 32 <= length) {
            uint* tmp = new uint[capacity * 2];
            for (int i = 0; i < capacity; i++) {
                tmp[i] = data[i];
            }
            for (int i = capacity; i < 2 * capacity; i++) {
                tmp[i] = 0;
            }

            delete[] data;
            data = tmp;
            capacity *= 2;
        }

        if (s) {
            data[length / 32] |= (1 << (length % 32));
        }

        length++;
    }

    // 임의의 위치의 원소를 접근한다.
    bool operator[](int idx) { return (data[idx / 32] & (1 << (idx % 32))) != 0; }

    // x 번째 원소를 제거한다.
    void remove(int idx) {

        for (int i = idx + 1; i < length; i++) {
            int prev = i - 1;
            int curr = i;

            // 만일 curr 위치에 있는 비트가 1이라면
            // prev 위치에 있는 비트를 1로 만든다.
            if (data[curr / 32] & (1 << (curr % 32))) {
                data[prev / 32] |= (1 << (prev % 32));
            }
            // 아니면 prev 위치에 있는 비트를 0으로 지운다.
            else {
                uint all_ones_except_prev = 0xFFFFFFFF;
                all_ones_except_prev ^= (1 << (prev % 32));
                data[prev / 32] &= all_ones_except_prev;
            }
        }

        length--;
    }

    // 현재 벡터의 크기를 구한다.
    int size() { return length; }

    ~Vector() {
        if(data) {
            delete[] data;
        }
    }    
};

int main() {
  // int 를 보관하는 벡터를 만든다.
  Vector<int> int_vec;
  int_vec.push_back(3);
  int_vec.push_back(2);

  std::cout << "-------- int vector ----------" << std::endl;
  std::cout << "첫번째 원소 : " << int_vec[0] << std::endl;
  std::cout << "두번째 원소 : " << int_vec[1] << std::endl;

  Vector<std::string> str_vec;
  str_vec.push_back("hello");
  str_vec.push_back("world");
  std::cout << "-------- std::string vector -------" << std::endl;
  std::cout << "첫번째 원소 : " << str_vec[0] << std::endl;
  std::cout << "두번째 원소 : " << str_vec[1] << std::endl;

  Vector<bool> bool_vec;
  bool_vec.push_back(true);
  bool_vec.push_back(true);
  bool_vec.push_back(false);
  bool_vec.push_back(false);
  bool_vec.push_back(false);
  bool_vec.push_back(true);
  bool_vec.push_back(false);
  bool_vec.push_back(true);
  bool_vec.push_back(false);
  bool_vec.push_back(true);
  bool_vec.push_back(false);
  bool_vec.push_back(true);
  bool_vec.push_back(false);
  bool_vec.push_back(true);
  bool_vec.push_back(false);
  bool_vec.push_back(true);
  bool_vec.push_back(false);

  std::cout << "-------- bool vector ---------" << std::endl;
  for (int i = 0; i < bool_vec.size(); i++) {
    std::cout << bool_vec[i];
  }
  std::cout << std::endl;
}