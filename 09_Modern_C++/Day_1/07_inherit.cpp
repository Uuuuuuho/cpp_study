class Base
{
	int value;
public:
	Base()      : value(0) {}
	Base(int n) : value(n) {}
};
class Derived : public Base
{
public:
    /*  
        Without adding member data, no need to add any constructor when only adding methods
        In C++98, Derived class was implemented like this.
        This is used when there is no new members, but only added functions!
    */
//    Derived() : Base() {}
//    Derived(int n) : Base(n) {}

    /* Since C++11 */
    using Base::Base;
};

int main()
{
	Derived d1;
	Derived d2(5);
}
