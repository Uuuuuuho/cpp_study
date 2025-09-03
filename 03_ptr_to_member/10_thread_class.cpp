#include <iostream>
#include <windows.h>

// 라이브러리 내부 틀래스
class Thread
{
public:
  void run()
  {
    // Start a native thread and pass the current object pointer as the
    // thread argument. The 4th parameter is a void* passed to the thread
    // entry function. Casting `this` to void* allows the static thread
    // entry to recover the object and call its instance method.
    // Note: this requires that the Thread object stays alive until the
    // spawned thread no longer uses it.
    CreateThread(0, 0, threadMain, (void*)this, 0, 0);
  }
  static DWORD __stdcall threadMain(void* p)
  {
    Thread* const self = static_cast<Thread*>(p);
    self->Main(); // Main(self)
    return 0;
  }
  // The thread entry calls this virtual method on the recovered object.
  // Making threadMain static avoids a hidden `this` parameter and matches
  // the C-style callback signature required by CreateThread.
  // Override Main() in derived classes to implement thread work.
  virtual void Main(){} // instance method called by the thread
};
// 라이브러리 사용자 코드
class MyThread : public Thread
{
public:
  virtual void Main() {std::cout << "스레드 작업" << std::endl;}
};