#include <string>

int main()
{
    /* 1. primitive type(int, double, etc. std type) obj is able to use "std::move".
          But no effect.
          std::move() : casting to rvlaue.
                        call move constructor of target type that results from type casting.
    */

   int n1 = 10;
   int n2 = std::move(n1);  /* This is same as "int n2 = n1". */


   /* 2. Same to pointer. */
   int* p1 = new int;
   int* p2 = std::move(p1); /* This is same as "int* p2 = p1". */

   /* Also, user must deallocate the variable when allocated by user. */
   delete p1;

   /* 3. std::move() only has effect for user defined types.
         (move constructor type)
   */
  std::string s1 = "to be or not to be";
  std::string s2 = std::move(s1); /* Call move constructor of 'string' class. */

  /* Move constructor is implemented in the most STL. */
}