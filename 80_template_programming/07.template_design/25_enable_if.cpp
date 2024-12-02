
/* std::enable_if
 * 템플릿 인자가 2개(bool, Type)
 * Type은 생략 가능, Type 생략시 void
 * 1번째 인자가
 *  True인 경우와 False인 경우 다른 구현 사용
 */
template <bool B, typename T = void>
struct enable_if {
    
};

template <typename T>
struct enable_if<true, T> {
    using type = T;
};

int main() {
    
    enable_if<true,  int>::type n1; // int n1
    enable_if<true,     >::type n2; // void n2, error (변수에는 void 사용불가)
    enable_if<false, int>::type n3; // type 없음
    enable_if<false,    >::type n4; // type 없음
}