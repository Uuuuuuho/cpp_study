#include <iostream>

/* CTRP를 사용하는 경우 주의사항
 *	기반 클래스가 템플릿이므로 파생 클래스의 갯수가 많아지면 
 *	"Code bloat" 현상이 발생할 수 있다.
 * 이를 해결하기 위한 방법이 "Thin Template"
 *  코드 중복을 막기위한 방안
 *  Class template을 만들때 "템플릿 인자를 사용하지 않는
 *  멤버는 기반 클래스(템플릿이 아닌)를 만들어 제공한다".
 */

class BaseWindow {
public:
	void Click() 	 { }
	void MouseMove() { }
};

template <typename T>
class Window : public BaseWindow
{
public:
	void event_loop()
	{
		static_cast<T*>(this)->Click();
	}
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