#include <mutex>

/* 	C++ 표준에서 lock()/unlock() 관리하는 도구는 4개입니다. 
		1. std::lock_guard		=> 가장 가볍고, 단순한 기능.
		2. std::unique_lock		=> 기능이 많다.
		3. std::shared_lock		=> std::shared_mutex 용
		4. std::scoped_lock		=> 여러개의 뮤텍스를 lock()/unlock()
*/

// 58page

std::mutex m;

int main()
{
	// lock_guard 를 사용하는 2가지 방법
	// 1. 생성자에서 lock 획득
	{
		std::lock_guard<std::mutex> lg(m);	// m.lock()
		/* 	lg.unlock() 같은 멤버함수는 없음. 
				소멸자에만 unlock()됩니다.
				함수 중간에서 unlock하려면 블럭{} 사용하세요.
		*/
		
	}

	// 2. 이미 lock 획득한 상태의 뮤텍스 관리
	if (m.try_lock())
	{
		std::lock_guard<std::mutex> lg(m, std::adopt_lock);
	}

	
}
