#include <iostream>
using namespace std;

int main()
{
  int i = 42, *p = &i, &r = i;
  decltype(r+0) b;    // ok: addition yields an int; b is an (uninitialized) int
  // decltype(*p) c;     // error: c is int& and must be initalized
}