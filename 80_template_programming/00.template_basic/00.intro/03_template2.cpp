/* 
 * template에 대한 다양한 관점
 *   함수(클래스)를 생성하는 틀(template)
 *   "a family of functions(class)"
 *   "generic functions(class)"
 */

/* 
 * template의 종류
 * 1. function template
 * 2. calss template
 * 3. variable template
 * 4. using template
 */

int square(int a) {
    return a * a;
}

double square(double a) {
    return a * a;
}

int main() {
    square(3);
    square(3.3);
}