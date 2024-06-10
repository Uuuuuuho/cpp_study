#include <iostream>
#include <thread>
#include <chrono>
#include <future>
using namespace std::literals;

int add(int a, int b)
{
    std::cout << "add : " << std::this_thread::get_id() << std::endl;
    std::this_thread::sleep_for(2s);

    std::cout << "finish add" << std::endl;
    return a + b;
}

int main()
{
    std::future<int> ft = std::async(add, 10, 20);

    std::cout << "continue main" << std::endl;

} // <= ft파괴. 여기서 add 스레드 대기.