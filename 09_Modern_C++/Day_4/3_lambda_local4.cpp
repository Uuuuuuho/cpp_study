int main()
{
	int v1 = 0, v2 = 0;

	
	auto f1 = [v1, &v2](int a) { ... }; // v1값, v2 참조 캡쳐
	auto f2 = [&v1, v2](int a) { ... }; // v2참조, v1 값 캡쳐

	auto f3 = [=](int a) { ... };	// 모든 지역변수를 값 캡쳐
	auto f4 = [&](int a) { ... };	// 모든 지역변수를 참조 캡쳐

	auto f5 = [=, &v2](int a) { ... }; // v2만 참조, 나머지 모두 값
	auto f6 = [&, v2](int a)  { ... }; // v2만 값,   나머지 모두 참조
	auto f7 = [&, &v2](int a) { ... }; // error.
							// 디폴트 모드와 다른 것만 표기해야 합니다.

	// 지역변수 v1, v2를 람다 표현식안에서 다른 이름으로 사용
	auto f8 = [x = v1, &y = v2](int a) { x, y };
			// int  x = v1;
			// int& y = v2;
}
