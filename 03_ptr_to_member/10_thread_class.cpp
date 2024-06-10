#include <iostream>
#include <windows.h>

// 라이브러리 내부 틀래스
class Thread
{
public:
  void run()
  {
    // 1. 4번째 인자로 전달되는 this가 핵심.
    CreateThread(0, 0, threadMain,(void*)this, 0,0);
  }
  static DWORD __stdcall threadMain(void* p)
  {
    Thread* const self = static_cast<Thread*>(p);
    self->Main(); // Main(self)
    return 0;
  }
  virtual void Main(){} // void Main(Thread* const this)
};
// 라이브러리 사용자 코드
class MyThread : public Thread
{
public:
  virtual void Main() {std::cout << "스레드 작업" << std::endl;}
};