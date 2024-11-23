#include <iostream>
#include <string>

/* 
 * nontype template에 타입이 아닌 인자의 기본값을 결정지을 수 있음.
 * 타입도 디폴트로 지정이 가능함.
 * Template argument deduction은 링크(https://en.cppreference.com/w/cpp/language/template_argument_deduction)를 참고할 것.
 */
template <typename T, int num = 5>
T add_sum(T t) {
    return t + num;
}

template <typename T>
struct Compare {
    bool operator()(const T& a, const T& b) const { return a < b; }
};

// Functor에 대한 default template을 설정함.
template <typename T, typename Comp = Compare<T>>
T Min(T a, T b) {
    Comp comp;
    if (comp(a, b)) {
        return a;
    }
    return b;
}

int main() {
    int x = 3;
    std::cout << "x : " << add_sum(x) << std::endl;

    int a = 3, b = 5;
    std::cout << "Min " << a << " , " << b << " :: " << Min(a, b)
                << std::endl;

    std::string s1 = "abc", s2 = "def";
    std::cout << "Min " << s1 << " , " << s2 << " :: " << Min(s1, s2)
                << std::endl;
}