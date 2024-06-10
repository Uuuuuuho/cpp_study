#include <vector>
#include <thread>
#include <algorithm>
#include <functional>
#include <iostream>

void do_work(unsigned id)
{}

int main()
{
    // 핵심 1. 스레드를 생성하면 반드시 "join" 하거나 "detach" 해야 합니다.
    std::thread t1(&do_work, 1);
    std::thread t2(&do_work, 1);
    t1.join();
    t2.join();

    // 핵심 2. 여러개 스레드를 관리해야 한다면 std::vector 등으로 관리하는 것이
    //        편리합니다.
    std::vector<std::thread> v1; // 크기가 0인 vector

    for (int i = 0; i < 10; i++)
    {
        // 방법 1. std::move 로 넣기
//      std::thread t(&do_work, 1);
//      v1.push_back(t); // error. 복사 생성자가 없으므로..
//      v1.push_back(std::move(t)); //ok. move 는 가능

        // 방법 2. 임시객체 형태로 전달하면 rvalue 이므로 move 생성자 사용
//      v1.push_back( std::thread(&do_work, 1) );

        // 방법 3. emplace_back 사용
        // => std::thread 객체의 전달이 아닌,
        // => std::thread 를 만들때 사용할 인자 전달.
        v1.emplace_back(&do_work, 1);
    }
    // 모두 join 호출
    std::for_each(v1.begin(), v1.end(),
                    [](std::thread& t) { t.join(); });

    //=================================
    // vector 를 사용하는 또 다른 스타일
//  std::thread t3; // 스레드 생성 안됨
//  t3 = std::thread(&do_work, 1);  // 이 순간 스레드 생성

    std::thread t3(&do_work, 1); // 위 2줄은 결국  이 한줄과 동일
    t3.join();

    std::vector<std::thread> v2(10); // 10개의 객체를 미리 생성
                                     // 단 디폴트 생성자 사용

    std::cout << v2[0].get_id() << std::endl; // 아직 스레드 생성전 이므로
                                            // 유효 하지 않은 값

    for (int i = 0; i < 10; i++)
    {
        v2[i] = std::thread(&do_work, 1);
                    // 1. 이 순간 스레드가 생성 되면서
                    // 2. id, 핸들이 우변의 임시객체에 저장
                    // 3. 임시객체의 멤버가 v2[i]로 이동.
    }
    std::for_each(v2.begin(), v2.end(),
        [](std::thread& t) { t.join(); });
}

