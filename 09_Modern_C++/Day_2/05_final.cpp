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
    /* final : no more overriding. */
	virtual void foo()      override final {} 
	virtual void goo(int a) override {}
	virtual void hoo()      override {}
};

class Derived2 : public Derived1
{
public:
	virtual void foo()      override {}
	virtual void goo(int a) override {}
	virtual void hoo()      override {}
};

int main()
{
}