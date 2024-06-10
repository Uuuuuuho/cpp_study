#include <iostream>
#include <string>
#include <vector>

/*  'move' concept. 
    String memory management.
    => When string size is less than 16 characters, store object itself.
    => When string size is larger than 16 chs, allocate it into heap.
    This is called SSO (Small String Optimization).
*/

int main()
{
	std::string s1 = "to be or not to be";
	std::string s2 = "to be or not to be";

    std::cout << (void*)s1.data() << std::endl;
    std::cout << (void*)s2.data() << std::endl;

	std::string s3 = s1;            /*  Deep copy (copy string itself). */
	std::string s4 = std::move(s2); /*  s2's string resource is used by s4
                                        s2 has no more resource.
                                    */

    std::cout << (void*)s3.data() << std::endl;
    std::cout << (void*)s4.data() << std::endl;
	std::cout << s1 << std::endl; 
	std::cout << s2 << std::endl;


}

