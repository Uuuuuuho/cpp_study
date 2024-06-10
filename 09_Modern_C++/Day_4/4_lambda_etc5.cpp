#include <functional>

int add(int a, int b) { return a + b; }

// 람다표현식은 인자를 받는 방법 

// 함수를 만들때 인자로 "호출 가능한 객체를 받는 최선의 방법"
// 호출 가능한 객체 : 함수, 함수객체, 람다 표현식등


// 방법 1. 함수 포인터
// => 캡쳐한 람다 표현식은 받을수 없다.
// => 함수 포인터로 변환을 지원하지 않는 함수 객체를 받을수 없다.
// => f 사용시 인라인 치환 안됨.

// 장점 : 템플릿이 아니므로 코드 증가 안함
// void find_if(int(*f)(int, int)) { f(1, 2); }

// 방법 2. std::funtion 사용
// 특징 1. f(1,2) 가 인라인 치환은 안됨
//     2. 호출가능한 모든 것을 받을수 있다.
//     3. 템플릿이 아니므로 코드 증가도 안됨.
//void find_if( std::function<int(int, int)> f) { f(1, 2); }


// 방법 3. 템플릿 - call by value
// 단점 : template 이므로 find_if 가 여러개 생성됨
// 장점 : f(1,2) 는 인라인 치환됨

// 복사본에 대한 오버헤드는 없나요 ?
// => 대부분의 함수객체는 크기가 작습니다. 
// => 따라서, 이방법은 나쁘지 않습니다.. 적극 권장
//template<typename T>
//void find_if(T f) { f(1, 2); }

// 방법 4. 템플릿 - lvalue reference
// => 람다표현식은 임시객체인데..
// => lvalue reference로는 받을수 없다.
// template<typename T>
// void find_if(T& f) { f(1, 2); }


// 방법 5. 템플릿 - const lvalue reference
// => operator() 가 상수 멤버 함수 인것만 호출할수 있게 된다
// => mutable 람다 표현식을 사용할수 없다.
/*
template<typename T>
void find_if(const T& f) 
{
	f(1, 2);    // f.operator()(1,2) 에서 f는 상수 객체이므로
				// () 연산자함수는 반드시 상수 함수 이어야 한다.
}
*/
// 방법 6. T&& forwarding reference
// => 나쁘지 않은 방법. 자주 사용!
// => 인자로 받게 되는 함수객체의 크기가 큰경우 이 방법이 좋다.
template<typename T>
void find_if(T&& f)
{
	f(1, 2);    
}

int main()
{
	int v = 0;
	find_if( [](int a, int b) { return a + b; } );
	find_if( [v](int a, int b) mutable { return a - b + v; } );

	find_if( add );
	find_if( std::plus<int>() ); // C++ 표준 함수 객체
}

// 결론 : 람다표현식을 함수 인자로 받으려면
// => 아래 중에서 한개 선택하세요.
// 1. foo(T f) 
// 2. foo(T&& f)
// 3. foo( std::function<int(int, int)> f)

// 뭐가 좋나요 ?? 상황에 따라 다릅니다.
// find_if 라면 전달되는 함수객체의 크기가 크지 않고
// 인라인 치환성이 중요 하므로 - T f !!!

// cppreference.com  std::find_if 찾아보세요  3번째 인자 확인해보세요