#include <iostream>
#include <vector>
#include <list>

// void print_first_element(const std::vector<int>& v) {

//     int n = v.front();

//     std::cout << n << std::endl;
// }

// template <typename T>
// void print_first_element(const std::vector<T>& v) { // 임의의 타입에 대한 함수

//     T n = v.front();

//     std::cout << n << std::endl;
// }

template <typename T>
void print_first_element(const T& v) { // 임의의 컨테이너에 대한 함수

    // T: list<double>
    // ? n = v.front(); // C++11부터는 "auto" 사용하면 됨.

    std::cout << n << std::endl;
}

int main() {

    // std::vector<int> c = { 1, 2,3, 4, 5 };
    // std::vector<double> c = {1, 2, 3, 4, 5};
    std::list<double> c = {1, 2, 3, 4, 5};

    print_first_element(c);
}