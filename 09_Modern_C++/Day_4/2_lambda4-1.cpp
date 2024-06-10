#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    std::vector<int> v = {1,2,3,4,5};

    /*  아래 코드를 생각해보세요.
        sort() 함수는 몇개 생성될까요?
        => 3개, lambda는 모두 typeid가 다르기 때문.
        => 그래도 sort는 inline이 되기 때문에 성능상 크게 차이는 없음.
    */
    std::sort(v.begin(), v.end(), [](int a, int b){ return a < b; });
    std::sort(v.begin(), v.end(), [](int a, int b){ return a < b; });
    std::sort(v.begin(), v.end(), [](int a, int b){ return a < b; });

    /*  동일한 람다표현식을 여러번 사용하면 auto 변수에 담아서 사용하는 것이 좋습니다. */
    auto f = [](int a, int b){ return a < b; };
                /* class xxx{}; xxx() */
    
    /* 아래 코드는 하나의 sort만 생성함. */
    std::sort(v.begin(), v.end(), f);
    std::sort(v.begin(), v.end(), f);
    std::sort(v.begin(), v.end(), f);

    /*  이런 경우는 람다보다도 less{}를 사용하는것도 좋습니다. 
        아래 코드는 모두 동일한 typeid를 가지기 때문에 하나의 sort만 생성됨.
    */
    std:;sort(v.begin(), v.end(), std::less<int>{});
    std:;sort(v.begin(), v.end(), std::less<int>{});
    std:;sort(v.begin(), v.end(), std::less<int>{});
}
