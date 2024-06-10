// 6_enable_if1.cpp

// 아래 enable_if 는 이미 C++11 표준입니다.
// => 구현도 아래와 거의 동일합니다.
template<bool, typename T = void > struct enable_if
{
	using type = T;
};
template<typename T> struct enable_if<false, T> 
{
	// 핵심 : 부분 특수화 버전은 "type" 이 없다는 점입니다.
};

int main()
{
	// 아래 코드에서 각 변수의 타입은 ?
	enable_if<true, int>::type  n1; // int n1
	enable_if<true>::type       n2; // void n2  void 변수생성안되므로
									//			error
	enable_if<false, int>::type n3; // error. false 버전에는
									//        "::type" 이 없다.

	// 정리
	// enable_if<조건, A>::type 에서 "::type" 은!!

	// 조건이 true  이면 : "A" 과 동일
	// 조건이 false 이면 : "::type" 자체가 없다
}