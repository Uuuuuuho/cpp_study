#include <iostream>
#include <thread>
#include <future>
#include <chrono>
using namespace std::literals;

// 31 page

// 스레드에서 결과값을 얻을때는
	// promise와 future 객체를 사용함.

// 1. 스레드 함수는 std::promise 객체를 참조로 받아야함.
void add(std::promise<int> &pro, int a, int b)
{
	// std::this_thread::sleep_for(2s);

	int result = a + b;

	// 2. 스레드가 결과를 주스레드에 전달하려면 promise 객체에 넣어주면 됨.
	pro.set_value(result);	// 한번만 가능.
													// 여러번 set_value 안됨.
													// 여러번 하려면, 다양한 동기화 기술을 사용해야함.
	
	std::cout << "thread terminated" << std::endl;
	std::this_thread::sleep_for(2s);
}

int main()
{
	// 1. promise 객체를 만들고, promise 안에 있는 future 객체를 꺼냄.
	std::promise<int> pro;

	std::future<int> ft = pro.get_future();

	// 2. thread 생성시, promise를 참조로 전달.
	std::thread t(add, std::ref(pro), 10, 20);

	std::cout << "main keep going" << std::endl;

	// 3. 스레드의 연산 결과를 대기하려면 future의 get() 호출.
	int result = ft.get();

	std::cout << result << std::endl;

	t.join();	// thread termination의 대기
						// 현재는 연산이 종료되었는지를 대기하는 방법은 없다.
}



