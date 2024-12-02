#include <iostream>

template <typename T>
class Window
{
public:
	void event_loop() // 사실 "void event_loop(Window* this)"가 호출되는 것.
	{
		// Click();	  // this->Click <= base class의 Click을 호출함
		// 아래는 CTRP가 적용된 예시
		static_cast<T*>(this)->Click(); // virtual function이 아니라도 derived class의 함수를 호출함.
	}
	// virtual function이 아니기 때문에 base class의 
	void Click()     { std::cout << "Window Click" << std::endl; }
	void MouseMove() { }
};

class MainWindow : public Window <MainWindow>
{
public:
	void Click() { std::cout << "MainWindow Click" << std::endl; }
};

int main()
{
	MainWindow w;
	w.event_loop();
}