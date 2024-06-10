#include <chrono>
#include <iostream>
#include <thread>
using namespace std::literals;

// �ٽ�. ���Ḧ ���ؼ� ��ӵ� ���� ����
// �ֽ����尡 ���ο� �����带 "���Ҷ� ����ǰ� �Ϸ���"
// ��ӵ� �޽����� ��������.

// �̸��� �ᱹ, �ֽ������ foo �� �����ϴ� �����尡 ���� �����ؾ� �ϴ� �� �Դϴ�.
// �̷����� "cooperative cancelation" �̶�� C# ������ �̾߱� �մϴ�.

void foo(bool &quit_signal)
{
    for (int i = 0; i < 10; i++)
    {
        std::this_thread::sleep_for(500ms);
        std::cout << "foo : " << i << std::endl;
        if (quit_signal) break;
    }
    std::cout << "foo terminated\n";
}

int main()
{
    bool quit = false;
    std::thread t1(foo, std::ref(quit));

    std::this_thread::sleep_for(1s);
    
    quit = true;    // quit signal ����

    t1.join();
}