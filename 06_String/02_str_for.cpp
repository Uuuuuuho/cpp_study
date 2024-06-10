#include <string>
#include <iostream>
using std::string;
using namespace std;

int main()
{
  string str("some string");
  for (auto c: str) cout << c << endl;

  string s("Hello World!");
  decltype (s.size()) punct_cntt = 0;

  for (auto c: s)     // for every char in 's'
    if(ispunct(c))    // if the character is punctuation
      ++punct_cntt;   // increment the punctuation counter
  cout << punct_cntt << " punctuation characters in " << s << endl;
}