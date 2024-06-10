#include <iostream>
#include <atomic>
#include <thread>
#include <mutex>
#include <chrono>
using namespace std::literals;

void init()
{
	std::cout << "start init" << std::endl;
	std::this_thread::sleep_for(5s);
	std::cout << "finish init" << std::endl;
}

/* 
std::once_flag flag;

void foo()
{
	std::call_once(flag, init);

	std::cout << std::this_thread::get_id() << " : finish foo" << std::endl;
}
 */

std::atomic<bool> init_flag = false;
void foo()
{
	call_once_nonblock(init_flag, init);
	std::cout << std::this_thread::get_id() << " : finish foo" << std::endl;
}

template<typename T>
void call_once_nonblock(std::atomic<bool>& flag, T func)
// template<typename T, typename ... Types>
// void call_once_nonblock(std::atomic<bool>& flag, T func, Types&& ...args)
{
    bool b = false;

    if(flag.compare_exchange_weak(b,true)){     // multi-thread에 안전하게 동작하도록 하기 위한 C++ atomic API
        // if(flag==b) falg = true, return true;
        // else b = true
        // 위 동작은 atomic하게...
        func();
        // func(std::forward<Types>(args)...);
	    std::cout << std::this_thread::get_id() << " : finish foo" << std::endl;
    }
}

int main()
{
	std::thread t1(foo);
	std::thread t2(foo);
	std::thread t3(foo);

	t1.join();
	t2.join();
	t3.join();
}