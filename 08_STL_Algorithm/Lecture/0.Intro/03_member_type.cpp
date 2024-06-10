#include <iostream>
#include <list>
#include <vector>

// 인자로 출력된 첫번째 인자
// void print(std::vector<int>& c){ // double에 대해서 컴파일 에러
//     int n = c.front();
//     std::cout << n << std::endl;
// }

/* vector만 작동함 */
// template<typename T>
// void print(std::vector<T>& c){   // vector 컨테이너가 아니면 컴파일 에러..
//     T n = c.front();             // 활용도를 높이려면 어떻게 해야하나? => template::value_type
//     std::cout << n << std::endl;
// }


/* ======== */
/* STL 원리 */
template<typename T> class list{
public:
    typedef T value_type; // 핵심...
};

// 예시
// list<int> s = {1,2,3};
// list<int>::value_type n = s.front(); // n은 int

template<typename T>
void print(T& c){
    // T : list<double>
    // T::value_type => list<double>::value_type
    typename T::value_type n = c.front();
    std::cout << n << std::endl;
}

int main(){
    // std::vector<int> v = {1,2,3};
    // std::vector<double> v = {1,2,3};
    std::list<double> v = {1,2,3};
    print(v);
}
