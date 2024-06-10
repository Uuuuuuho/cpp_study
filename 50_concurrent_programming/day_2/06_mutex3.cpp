#include <iostream>
#include <thread>
#include <mutex>
#include <syncstream>   // C++20

std::mutex m;

void foo()
{
    // m.lock();
	// std::cout << "foo : " << std::this_thread::get_id() << std::endl;
    // m.unlock();

    std::osyncstream sout(std::cout);
    sout << "foo : " << std::this_thread::get_id() << std::endl;
}

int main()
{
	std::thread t(foo);
    // m.lock();
    // std::cout << "main : " << std::this_thread::get_id() << std::endl;
    // m.unlock();
    std::osyncstream sout(std::cout);
    sout << "main : " << std::this_thread::get_id() << std::endl;
	t.join();
}