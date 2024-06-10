#include <mutex>

/* 	C++ ǥ�ؿ��� lock()/unlock() �����ϴ� ������ 4���Դϴ�. 
		1. std::lock_guard		=> ���� ������, �ܼ��� ���.
		2. std::unique_lock		=> ����� ����.
		3. std::shared_lock		=> std::shared_mutex ��
		4. std::scoped_lock		=> �������� ���ؽ��� lock()/unlock()
*/

// 58page

std::mutex m;

int main()
{
	// lock_guard �� ����ϴ� 2���� ���
	// 1. �����ڿ��� lock ȹ��
	{
		std::lock_guard<std::mutex> lg(m);	// m.lock()
		/* 	lg.unlock() ���� ����Լ��� ����. 
				�Ҹ��ڿ��� unlock()�˴ϴ�.
				�Լ� �߰����� unlock�Ϸ��� ��{} ����ϼ���.
		*/
		
	}

	// 2. �̹� lock ȹ���� ������ ���ؽ� ����
	if (m.try_lock())
	{
		std::lock_guard<std::mutex> lg(m, std::adopt_lock);
	}

	
}
