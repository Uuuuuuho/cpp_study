#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
using namespace std::literals;

std::mutex       m1, m2, m3;
std::timed_mutex tm1, tm2, tm3;

/*  unique_lock�� ����� �����ϴ�. 
    condition variable�� unique_lock�� ���� ����ؾ���.
*/

int main()
{
    std::unique_lock<std::mutex> u1;                        // ���� ���ؽ��� ����ȵ�
    std::unique_lock<std::mutex> u2(m1);                    // �����ڿ��� m1.lock()
    std::unique_lock<std::mutex> u3(m2, std::try_to_lock);  // �����ڿ��� m2.try_lock() ����

    // u3 (unique_lock�� try_lock)�� mutex lock acquire�� �Ʒ�ó�� ������.
    if (u3.owns_lock())
        std::cout << "acquire lock" << std::endl;
    else
        std::cout << "fail to lock" << std::endl;

    // �̹� lock()�� �� mutex�� unlock()�� �ڵ�����
    m3.lock();
    std::unique_lock<std::mutex> u4(m3, std::adopt_lock);   

    //==================================================================
    // ���� lock() ���ߴµ�, �̷��� lock()�� �� ���̴�.
    std::unique_lock<std::timed_mutex> u5(tm1, std::defer_lock);
    auto ret = u5.try_lock_for(2s);     // �� �Լ��� ����Ϸ���
                                        // u5�� �ݵ�� timed_mutex�̿�����.

    // �����ڿ��� try_lcok_for(2s)
    std::unique_lock<std::timed_mutex> u6(tm2, 2s);  // tm2.try_lock_for() ���
    std::unique_lock<std::timed_mutex> u7(tm3, std::chrono::steady_clock::now() + 2s);
    // tm3.try_lock_until() ���

    u2.unlock(); // explicit unlock()�ϴ� ��� �Լ� ����
}
