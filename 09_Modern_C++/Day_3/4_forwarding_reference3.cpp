int n = 0;

void f1(int&  r) {}
f1(n); /* Ok. */
f1(0); /* Error. */

void f2(int&& r) {}
f2(n);  /* Error. */
f2(0);  /* Ok. */

/* 함수 인자로 
   (lvalue reference) int& : int type의 lvaue만 받겠다.

   (rvalue reference) int&&: int type의 rvalue만 받겠다.

   (lvalue reference) T& : 임의 타입의 lvalue만 받을 수 있음.
   template T&이라고하더라도 어차피 lvalue임.
   왜냐하면 T& 다음 '&'가 2개가 않을 것이기 때문.

   (universal reference) T&& : 모든 타입의 lvalue와 rvalue를 모두 받을 수 있다.
   *universal"이 "모든 것을 받아드리는"의 의미를 가지기 때문.
   *C++ 표준 위원회에서는 이를 "forwarding reference"라고 부름.

   핵심 1. "받을 수 있다"라는 말은 "받을 수 있는 함수를 생성한다"의 의미이다.
   핵심 2. 생성된 함수는 모두 call by value가 아닌 reference!!

   lvalue 전달 f4(n) : T=int&  T&&=int& &&, 최종함수 : f4(int&)
   rvalue 전달 f4(3) : T=int   T&&=int &&,  최종함수 : f4(int&&)

*/

template<typename T> void f3(T& a)
{
}

template<typename T> void f4(T&& a)
{
}

int main()
{
    int n = 0;

    /* 1. 사용자가 타입을 명시적으로 전달하는 경우. */
    f3<int>(n)   ;  /* T=int   T&=int&    f3(int& a). 반드시 lvalue만 보내야함. rvalue를 보내면 compile error. */
    f3<int&>(n)  ;  /* T=int&  T&=int&    f3(int& a). 마찬가지. */
    f3<int&&>(n) ;  /* T=int&& T&=int&& & f3(int& a). 마찬가지. */

    /* 2. 사용자가 타입을 전달하지 않는 경우 
       => 함수 인잘를 보고 T 타입 결정후 함수생성
    */
    f3(3);  /* 3을 보고 T를 int로 결정하려고 하는데..
               T=int, int&, int&& 중 어떠한 것으로 결정해도 3을 받을 수 없다.
               따라서 Error.
               결론은 f3()은 lvalue만 받을 수 있고, rvalue는 받을 수 없음.
            */
    f3(n);

    /* 1. 타입을 명시적으로 전달하는 경우. */
    f4<int>(3)   ;  /* T=int   T&=int&&    => int&&  f4(int&& a). 반드시 rvalue만 보내야함. lvalue를 보내면 compile error. */
    f4<int&>(n)  ;  /* T=int&  T&=int& &&  => int&   f4(int& a).  반드시 lvalue만 보내야함. rvalue를 보내면 compile error. */
    f4<int&&>(3) ;  /* T=int&& T&=int&& && => int&&  f4(int&& a). 반드시 rvalue만 보내야함. lvalue를 보내면 compile error. */

    /* 2. 타입인자를 전달하지 않으면 함수 인자를 보고 타입을 결정
          => 컴파일러가 T를 어떻게 결정했을지 예측해보세요.
    */

    f4(n);  /* 1. n은 int이므로 T=int로 결정하면, 생성된 함수 : f4(int&& a)가 됨.
                  => f4(n)는 Error. Compiler가 이런식으로 추론하지 않음.
               2. T=int&로 결정하면 f4(int&) 함수 생성하므로
                  => f4(n)은 에러 아님. 따라서 compiler가 이런식으로 추론함.
                  T=int&, T&&=int& &&, 생성된 함수: f4(int& a)
            */

    f4(3);  /* T=int, T&&=int&&, 생성된 함수: f4(int&& a) */
}
