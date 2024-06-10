#include <thread>

// 27 page
// copy, move

void foo() {}
void goo() {}

void f1(std::thread t)
{
    t.join();
}
std::thread f2()
{
    return std::thread(&foo);
}

int main()
{
    std::thread t1(&foo);
    std::thread t2(&goo);

    // 1. swap
//  t1.swap(t2); // ok. 결국 내부적으로는 "t1, t2가 관리하는 thread 핸들을 swap"


    // 2. copy 는 안되고, move 는 됩니다.
//  std::thread t3 = t1; // error
    std::thread t4 = std::move(t1); // ok

//  t1.join(); // 예외.. 자신이 관리하던 스레드는 이미 t4가 가짐
    t4.join(); // ok


    // 3. 
    std::thread t5; // 스레드 생성 안됨

//  t5 = t4; // error. 대입도 안됨
//  t5 = std::move(t4);     // ok
    t5 = std::thread(&foo); // ok. 스레드 생성
         // 임시객체 생성 표기법, 
         // 임시객체는 rvalue 이므로 move 됩니다.

    // 4. 스레드를 함수 인자로 전달
    std::thread t6(&foo);
//  f1(t6); // error. std::thread t = t6 이므로 복사 생성자 호출

    f1(std::move(t6));      // ok
    f1(std::thread(&foo));  // ok

    // 5. 함수가 스레드 반환도 가능
    std::thread t7 = f2();  // ok. f2는 값 반환
                            // 값 반환은 임시객체 반환 하므로
                            // move 호출. 
}

// Windows API
// WaitForSingleObject( 스레드 핸들) : 스레드 종료를 대기
// WaitForSingleObject( 프로세스 핸들) : 프로세스 종료를 대기

// linux
// pthread_join(스레드핸들) : 스레드 대기 
//???                       : 프로세스 대기

// C++ 표준에서는 프로세스 대기는 없습니다.