#include <iostream>
#include <thread>
#include <chrono>
#include <future>
using namespace std::literals;

int add(int a, int b)
{
    std::cout << "add : " << std::this_thread::get_id() << std::endl;
    std::this_thread::sleep_for(2s);
    return a + b;
}
int main()
{
    // std::future<int> ft = std::async( add, 10, 20);

/*   
    핵심 : async 사용시, "launch 옵션" 전달 가능함.
    std::launch::async : 함수를 새로운 스레드로 실행해 달라는 것.
    std::launch::deferred : 지연된 실행, 새로운 스레드를 만들지 말고
                            현재 스레드가, "ft.get()"할 때 실행해 달라.
*/
    // std::future<int> ft = std::async(std::launch::async,add,10,20);  // add를 스레드로 실행한뒤 return 값 받기
    // std::future<int> ft = std::async(std::launch::deferred,add,10,20); 

    std::future<int> ft = std::async(std::launch::async | std::launch::deferred,add,10,20);

    // std::future<int> ft = std::async(add,10,20);

    std::cout << "continue main : " << std::this_thread::get_id() << std::endl;
    // std::this_thread::sleep_for(2s);
    int ret = ft.get();

    std::cout << "result : " << ret << std::endl;
}



