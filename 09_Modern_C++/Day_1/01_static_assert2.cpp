#include <iostream>
using namespace std;

#pragma pack(1)
struct PACKET
{
    char cmd;
    int data;    
};

/* can pass this static_assert when compiler does not pad anything. */
static_assert(sizeof(PACKET)==sizeof(char)+sizeof(int), 
                "error, unexpected padding");

int main()
{
    std::cout << sizeof(PACKET) << std::endl; 
}