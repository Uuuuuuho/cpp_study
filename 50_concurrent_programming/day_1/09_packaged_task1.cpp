#include <iostream>
#include <thread>
#include <future>

// 39 page

// promise 모델 : 스레드 함수의 연산의 결과를 promise 를 통해 전달
// => 결국, 함수를 만들때 "스레드로 실행할것을 고려" 해서 만든다는 것

// => 스레드로 실행할것을 고려 하지 않은 일반 함수를 스레드로 실행하고
//    결과를 얻고 싶다면 "packaged_task"

// add 함수가 promise 를 통해서 반환값 전달
// 다른 스레드에 반환

void add(std::promise<int>& p, int a, int b)
{
	p.set_value(a + b);
}

int main()
{
	std::promise<int> pm;
	std::future<int> ft = pm.get_future();

	std::thread t(add, std::ref(pm), 10, 20);

	int ret = ft.get();

	t.join();
}
