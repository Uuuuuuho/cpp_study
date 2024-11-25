#include <iostream>
#include <vector>
#include <list>

/* STL과 value_type 멤버
 * STL의 모든 컨테이너에는 "value_type"이라는 멤버 타입이 있다. 
 * 컨테이너가 저장하는 타입이 필요할 때 사용.
 */
template <typename T>
void print_first_element(const T& v) { // 임의의 컨테이너에 대한 함수

    // T: list<double>
    // ? n = v.front(); // C++11부터는 "auto" 사용하면 됨.
    
    // T::value_type n = v.front(); // value_type이 non-type이 아니라 dependent type이기 때문에 "typename" 키워드를 붙여줘야함.
    typename T::value_type n = v.front();    
    auto s = v.front(); // C++11부터는 "auto"를 사용하면 되는데 안되는 경우도 간혹 존재함.

    std::cout << n << std::endl;
}

int main() {

    // std::vector<int> c = { 1, 2,3, 4, 5 };
    // std::vector<double> c = {1, 2, 3, 4, 5};
    std::list<double> c = {1, 2, 3, 4, 5};

    print_first_element(c);
}