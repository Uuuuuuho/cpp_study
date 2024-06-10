// 10_user_define_literal2
#include <iostream>
#include <string>
#include <chrono>
#include <thread>
using namespace std::chrono; 

using namespace std::literals; /* standard suffix literal */

void foo(const char* s) { std::cout << "const char*"; }
void foo(std::string s) { std::cout << "string"; }

int main()
{
	foo("hello");   /* const char* */
	foo("hello"s);  /* string 
                        Operator""s("hello") returns string
                        Integer literal prefix argument is usigned long long
                        String literal is const char*
                    */
    // auto x[3] = {"AA", "BB", "CC"};
    auto s1 = "hello";
    auto s2 = "hello"s;

	std::chrono::seconds sec1(3); /* 3 seconds. */
	auto sec2 = 3s;			    // Same as above.

	std::chrono::seconds sec3 = 1h + 3min + 20s;

	std::cout << sec3.count() << std::endl;

	// RUST 코드
//	let n1 = 10_i32; // i32 타입의 리터럴 10
//	let n2 = 10_u32; // u32(unsigned int 32bit)
}


