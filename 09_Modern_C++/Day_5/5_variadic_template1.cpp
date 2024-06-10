// 7_가변인자템플릿1 - 225 page
// 가변인자 클래스 템플릿

template<typename T> class vector
{
};

// C++11 부터 템플릿 인자를 "가변 갯수"로 전달 가능합니다.
template<typename ... Types> class tuple
{
};

int main()
{
	vector<int> v1;			// ok
//	vector<int, double> v2;	// error

	// tuple 에는 타입을 몇개라도 전달 가능합니다.
	tuple<int> t1;			// Types : int
	tuple<int, double> t2;	// Types : int ,double
	tuple<> t0;
}