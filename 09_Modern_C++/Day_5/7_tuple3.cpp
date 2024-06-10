// Step 2. 값 한개 보관하기

template<typename ... Types> struct tuple
{
	static constexpr int N = 0; 
};

// tuple 사용시 최소 한개 이상의 타입이 있는 경우를 위한 부분 특수화
template<typename T, typename ... Types>
struct tuple<T, Types...>
{
	T value;

	tuple() = default;
	tuple(const T& n) : value(n) {}

	static constexpr int N = 1;
};

int main()
{
	tuple<> t0;
	tuple<short> t1;
	tuple<double, short> t2;
	tuple<int, double, short> t3; // t3는 한개(int, 10)만 보관
}