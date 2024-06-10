#include <iostream>
#include <thread>
#include <future>
#include <chrono>
using namespace std::literals;

// promise & future ��
// => �ڽ� �����尡 ������ ������ ����� ��� ���� ���
// => �ѹ��� ��밡��.

void add(std::promise<int>& pro, int a, int b)
{
	std::this_thread::sleep_for(2s);

	int result = a + b;

	pro.set_value(result);	
}

int main()
{
	std::promise<int> pro;
	std::future<int> ft = pro.get_future();

	std::thread t(add, std::ref(pro), 10, 20);

	int result = ft.get();	// pro.set_value()�� �Ҷ� ���� ��� �մϴ�.

	std::cout << "�������Լ��� ��� : " << result << std::endl;

	t.join();	

}



