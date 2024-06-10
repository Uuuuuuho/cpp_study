#include <iostream>
#include <chrono>
#include <string>

// time_point : "���� �ð� + ����� �ð�"
//              ex) 0��1�� 1�� ���Ŀ� 1000000000�� ������
// 
// epoch_time : "1970�� 1�� 1��" ���� ����� �ð�
int main()
{
    // ���� �ð��� ���ϴ� �ڵ�
    std::chrono::system_clock::time_point tp = 
                                std::chrono::system_clock::now();
                                            // static ����Լ� now()

    // 1970�� 1�� 1�� 0�� ����.
    std::chrono::nanoseconds ns = tp.time_since_epoch();

    std::cout << ns.count() << std::endl;

    std::chrono::hours h = 
        std::chrono::duration_cast<std::chrono::hours>(ns);
    
    std::cout << h.count() << std::endl;

    // time_point => ���ڿ��� ��ȯ.
    // 1. time_point => time_t �� ����
    time_t t = std::chrono::system_clock::to_time_t(tp);

    // 2. time_t �� ���ڿ��� ����
    char s[256] = { 0 };
    ctime_s(s, 256, &t);

    std::cout << s << std::endl;

}