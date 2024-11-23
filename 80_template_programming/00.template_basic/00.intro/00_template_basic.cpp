/* 
 * 함수 템플릿을 만들고 사용하지 않으면
 * => 인스턴스화(Instantiation) 되지 않는다.
 * => 실제 함수는 생성되지 않는다.
 */

/* 코드 폭발(Code Bloat)
 * => 템플릿이 너무 많은 타입에 대해 instantiation 되어서 코드 메모리가 증가하는 현상.
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