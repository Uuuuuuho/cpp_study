int main()
{
	int  n1 = 3.4;  /* 
                        Ok.. but warning.. 
                        However, very bad coding.
                        Error for other languages except for C/C++.
                    */
	char c1 = 500;  /*  
                        Ok.. but overflow.
                        Very bad coding.
                    */

	/* 
        Prevent narrow 
        "uniform initialization"
        => Error when data loss in {} initialization.
        C++ has been developed just like others.
    */
	int n2{ 3.4 };  /* Error. */
	char c2{ 500 }; /* Error. */

}