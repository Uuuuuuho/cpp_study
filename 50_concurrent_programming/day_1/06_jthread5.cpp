#include <chrono>
#include <iostream>
#include <thread>
using namespace std::literals;

// 4번처럼 "협력적 취소" 를 사용하려면 스레드당 한개씩의 cancel 변수가 필요 합니다.

// std::jthread 는 "협력적 취소" 모델을 제공합니다.

void foo(std::stop_token quit_token )
{
    for (int i = 0; i < 10; i++)
    {
        std::this_thread::sleep_for(500ms);
        std::cout << "foo : " << i << std::endl;

        if (quit_token.stop_requested())
        {
            break;
        }
    }
    std::cout << "foo 종료" << std::endl;
}



void goo()
{
    for (int i = 0; i < 10; i++)
    {
        std::this_thread::sleep_for(500ms);
        std::cout << "goo : " << i << std::endl;
    }
}
int main()
{
    std::jthread j1(foo);   // quit_token 을 보내는 코드가 없지만
                            // 자동 전달 됩니다.
    std::jthread j2(goo);

    j1.request_stop();
    j2.request_stop(); // 종료 신호를 보내지만, 조사하는 코드를 만들지 않았으므로
                        // 무시됩니다.
    std::this_thread::sleep_for(2s);
}