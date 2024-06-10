#include <iostream>
#include <thread>
#include <future>
using namespace std::literals;
// 40 page
// packaged task : 함수를 "보관" 했다가 "필요할때 스레드로 실행"
// async         : 함수를 "보관하지않고 즉시" "스레드로 실행" 후 "return 된 결과" 받기
//                 => 내부적으로 다시 "packaged_task" 사용

// std::thread  vs  std::async
// std::thread : 함수를 스레드로 실행, 결과(return 값)를 받을수 없다.
//				 => 결과를 얻으려면,다양한 기법 활용(promise/future 등)
// 
// std::async  : 함수를 스레드로 실행, 결과(return 값)를 받을수 있다.

int add(int a, int b)
{
	std::cout << "add" << std::endl;
	std::this_thread::sleep_for(2s);
	return a + b;
}
int main()
{
	std::future<int> ft = std::async(add, 10, 20); // add를 스레드로 실행해 달라.

	std::cout << "main 은 계속 실행" << std::endl;

	int ret = ft.get(); // 결과 대기

	std::cout << "add 결과 : " << ret << std::endl;
}
