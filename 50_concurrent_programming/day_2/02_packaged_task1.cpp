#include <iostream>
#include <thread>
#include <future>

// 39 page

// add �Լ��� promise �� ���ؼ� ��ȯ�� ����
// �ٸ� �����忡 ��ȯ
void add(std::promise<int>& p, int a, int b)
{
	p.set_value(a + b);
}

int main()
{
	std::promise<int> pm;
	std::future<int> ft = pm.get_future();

	std::thread t(add, std::ref(pm), 10, 20);

	int ret = ft.get();

	t.join();
}



