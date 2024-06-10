#include<iostream>
#include"post.h"
using namespace std;

int main(void) {
  char line[MAXLEN];
  while (cin.getline(line, MAXLEN)) {
    Expression e(line);
    try {
      /* Calculator for postfix operator
      *  Ex) 3 4 + 
      *  Ex) 7 8 *
      */
      Eval(e);
    }
    catch (char const*msg) {
     cerr <<"Exception: "<< msg <<endl;
    }
  }
}