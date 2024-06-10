#include <string>
using std::string;

int main()
{
  string s1;
  string s2 = s1;
  string s3 = "hiya";
  string s4(10,'c');    // cccccccccc
  string s5 = "hiya";   // copy initialization
  string s6("hiya");    // direct initialization
  string s7(10, 'c');   // direct initialization
}