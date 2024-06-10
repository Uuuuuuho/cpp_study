#include <iostream>
#include <thread>
#include <future>

// 스레드를 고려하지 않고 만들어진 일반 함수는 대부분
// "return 값" 으로 결과를 전달합니다.
int add( int a, int b)
{
	std::cout << "add" << std::endl;

	return a + b;
}

int main()
{
	// 1. "add" 함수를 담은 pakaged_task 객체를 생성합니다.
	// => 아래 코드에서 "task" 는 add 함수의 주소를 보관하게 됩니다.
	// => 아직, add가 실행된것은 아닙니다.
	std::packaged_task<int(int, int)> task(add);


	// 2. task 객체에서 future 를 꺼내세요
	std::future<int> ft = task.get_future();


	// 3. task 객체를 실행하면 됩니다.
	// => 스레드가 아닌 일반 호출로 실행도 됩니다.
	// task(10, 20); // add(10,20) 으로 실행됩니다.(스레드 생성 아님)

	// 스레드를 생성할때 task 객체를 "std::ref 또는 std::move" 로 보내면 됩니다.
	// std::ref(task) : task 를 계속 사용하고 싶을때
	// std::move(task) : task 를 한번만 사용한다면, 자원의 이동이 좋습니다.
	std::thread t(std::move(task), 10, 20); // add(10,20)을 스레드로 실행

	// 4. future 객체를 사용해서 결과 꺼내기.
	int ret = ft.get();

	std::cout << ret << std::endl;

	t.join();
}
// promise 모델   : add 함수를 만들때 스레드를 고려해서 만들어야 합니다.
// packaged task : 이미 만들어져 있던 함수를 
//					"보관" 했다가 "필요할때 스레드로 수행" 후 "결과"를 얻고 싶을때
//					=> 내부적으로는 결국 "promise/future"사용


