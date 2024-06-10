class Base
{
public:
	virtual void foo() {}
	virtual void goo(int a) {}
	virtual void hoo() {}
};

class Derived1 : public Base
{
public:
    /*  Example of redefined virtual functions by mistake. 
        => Mistake but not an error.
        => Compiler considers them as new virtual functions.
        => Cause of bugs.
    */
	virtual void fooo() {}
	virtual void goo(double a) {}
	virtual void hoo() const  {}
};

class Derived2 : public Base
{
public:
    /*  Since C++11, attatching 'override' is strongly recommended
        for virtual functions.
    */
	virtual void fooo()         override {}
	virtual void goo(double a)  override {}
	virtual void hoo() const    override {}
};

int main()
{
}