#include <iostream>
#include <thread>

// 26 page joinable()

int main()
{
    //  std::thread t1(&foo); 함수 전달. 스레드 생성됩니다.
    //  t1.join(); // ok


    std::thread t; // 함수 전달 안함. 스레드 생성 안됩니다.

//  t.join();   // 예외 발생합니다.

    try
    {
        t.join();
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    if (t.joinable())
        t.join();
}