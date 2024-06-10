#include <list>

/* STL inheritance is not good. */
class MyList : public std::list<int>
{
public:
    /* If ther eis not inheritance, it need to add the same constructors */
    // MyList(int sz, int value) : std::list<int>(sz, value){}
    // MyList(int sz) : std::list<int>(sz){}

    /* Constructor inheritance grammar with only one line! */
    using std::list<int>::list;

    void dump(){}   /* User defined method. */
};

int main()
{
	MyList st1(10, 3); // Init from 10 to 3
	MyList st2(10);
}
