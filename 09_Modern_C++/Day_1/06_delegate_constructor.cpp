#include <iostream>
// 6_위임생성자 - 24page
class Point // : public Base
{
public:
	int x, y;
public:
	/* 
        User code 
	    
        Point()			// : Base()
            Compiler added base class        
    */

	Point() : Point(0, 0) /* Delegating class from C++11  */
	{
        /*
            Another constructor?
            => Not working (until C++98)

            Point(0, 0);	// ok
                            // 하지만, 다른 생성자를 호출하는게 아니라
                            // 임시객체를 만드는 표기법 입니다.
        */
	}

	Point(int a, int b) : x(a), y(b)	// : Base()
	{
		/* Complicated code */
	}
};
int main()
{
	Point p;
	std::cout << p.x << std::endl;

}