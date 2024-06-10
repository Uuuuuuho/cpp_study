// 143 
#include <functional>

int main()
{
    /* 람다표현식을 담는 방법 */

    /* 1. auto 변수 - 가장 권장 */
	auto f1 = [](int a, int b) { return a + b; };

    /* 2. 함수 포인터 */
    int(*f2)(int, int) = [](int a, int b) { return a + b; };
                        /*  class xxx{}; xxx(); 이므로 
                            임시객체
                        */

    /* 3. std::function : 함수포인터와 유사한 기능의 STL 클래스 */
    std::function<int(int, int)> f3 = [](int a, int b){ return a + b; };

    /* 아래 3줄에 대해서 생각해보세요. */
    f1(1, 2);   /*  f1.operator()(1,2)... 
                    => 컴파일 시간에 f1의 타입을 조사해서 호출.
                    => 인라인 치환 지원.
                */
    f2(1, 2);   /*  f2에 담긴 주소를 꺼내서 호출
                    f2는 변수이므로 변할 수 있다.
                    => 인라인 치환 안됨.
                */
    f3(1, 2);   /*  => 인라인 치환 안됨. */
}