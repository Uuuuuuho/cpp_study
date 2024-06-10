#include <iostream>
#include <thread>
#include <windows.h>
#include <chrono>
using namespace std::literals;

// 24 page
// ������ �켱 ����
// ��κ��� OS �� �����ϴ� ������ ����� ���� ����ϸ�
// "�켱����"���� �����Ҽ� �ֽ��ϴ�.

// �׷���, std::thread ���� "�켱���� �����ϴ� ����� �����ϴ�."

void foo()
{
    auto tid = std::this_thread::get_id(); // ������ ID ���
}

int main()
{
    std::thread t(&foo);

    // t�� ������ �������� OS ������ �ڵ�(��ũ����) ���
    std::thread::native_handle_type handle = t.native_handle();

    // handle �� Ÿ���� �� OS ���� �ٸ��ϴ�. 
    // windows API ������ "HANDLE" �̶�� Ÿ���Դϴ�.

    // ���� OS ������API ����� �����մϴ�
    SetThreadPriority((HANDLE)handle, THREAD_PRIORITY_HIGHEST);


    t.join();
}