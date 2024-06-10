#include <iostream>
#include <string>
#include <thread>

// �⺻ OS�� �����ϴ� ������ ���
// �Լ� ��翡 ������ �ִ�. (���ڴ� �ַ� void*)

// C++ thread : ������� ������ �Լ��� ��翡 ������ ����.

void f1() { }
void f2(int a, double d) { }
void f3(int a, int& b, std::string&& s) { b = 100; }

int main()
{
    int n = 0;
    std::string s = "hello";

    // ���� ���� ���
    std::thread t1(&f1);
    std::thread t2(&f2,5,3.4);
    // std::thread t3(&f3,5, n, std::move(s)); // error.
    std::thread t3(&f3,5, std::ref(n), std::move(s)); // inter-thread parameter ��뿡 �־ race condition�� �߻��� �� �����Ƿ� ���α׷��� �ܰ迡�� ���ǰ� �ʿ���.

    t1.join();
    t2.join();
    t3.join();

    // ��, �����尣 ������ ������ ���� �����ϹǷ� �����ؼ� ����� ��.
}

