int foo() { return 100; }

int main()
{
	int ret = foo();
	if (ret == 0)
	{
	}
    /*  Since C++17, code above can be expressed as below. 
        This is called "if with init" grammar.
        if(init; condition)
    */
    if(int ret2 = foo(); ret2 == 0)
    {        
        /* 'ret2' can be used here to check something.
            Then, 'ret2' is destructed outside this bracket.
        */
    }

}