// 58 page
class Vector
{
	int sz;
public:
    /* 
        Explicit constructor :  Only allow direct init.
                                Not allow copy init.
    */
	explicit Vector(int s) : sz(s) {}
};
void foo(Vector v) {} 				  

int main()
{
    /* Possible to use like below when only one argument constructor exits. */
	Vector v1(10);      /* C++98 direct init */
	Vector v2 = 10;     /* C++98 copy init   */
	Vector v3{ 10 };    /* C++11 direct init */
	Vector v4 = { 10 }; /* C++11 copy init   */

	//----------------
	foo(10); // ?
}







