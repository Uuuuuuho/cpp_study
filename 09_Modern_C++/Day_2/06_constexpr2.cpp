/*  C++11 added 'constexpr'.

    constexpr : Compiler must know the value in compile time.
    const     : To make readonly variable.
*/

int main()
{
	int n = 0;

	const int c1 = 0;   /* Ok. */
	const int c2 = n;   /* Ok. n is var. Compiler cannot know the value in compiler time. */

	constexpr int c3 = 0;   /* Ok. */
	constexpr int c4 = n;   /* Error. Compiler must know the value in compile time. */

}