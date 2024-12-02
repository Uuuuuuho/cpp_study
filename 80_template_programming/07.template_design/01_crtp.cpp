#include <iostream>

/* GUI event를 가상함수 기반으로 처리하는 경우
 * => GUI event는 아주 많은 종류가 있다.
 * => "가상함수 테이블의 크기에 대한 메모리 오버헤드"가 있다.
 */

class Window
{
public:
	void event_loop() 
	{
		Click();
	}
    // Default virtual function: derived class에서 정의하지 않으면 사용되는 기본 가상함수
	virtual void Click()     { std::cout << "Window Click" << std::endl; }
	virtual void MouseMove() { }
};

class MainWindow : public Window 
{
public:
	void Click() override { std::cout << "MainWindow Click" << std::endl; }
};

int main()
{
	MainWindow w;
	w.event_loop();
}