// 1_함수객체7.cpp
// cmp1, cmp2, Less, Greater 복사해오세요

inline bool cmp1(int a, int b) { return a < b; }
inline bool cmp2(int a, int b) { return a > b; }
struct Less { inline bool operator()(int a, int b) { return a < b; } };
struct Greater { inline bool operator()(int a, int b) { return a > b; } };

template<typename T>
void foo(T f)
{
	bool b = f(1, 2); // A
}
int main()
{
	Less    f1;
	Greater f2;
	foo(cmp1);
	foo(cmp2);
	foo(f1);
	foo(f2);
}
// 1. foo 함수는 몇개 생성될까요 ?
// 2. 각 foo 함수에서 "A" 부분의 인라인 치환에 대해서 생각해 보세요
// 3. foo와 main 을 제외하고 기계어 코드로 생성된 함수는 무엇이 있을까요?