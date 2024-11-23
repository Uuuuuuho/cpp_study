template<typename T>
T square1(T a) {
    return a * a;
}
template<class T> // typename으로 작성하는 것과 생성되는 코드는 동일함.
T square2(T a) {
    return a * a;
}
/* C++20부터 */
auto square3(auto a) {
    return a * a;
}

int main() {
    square1<int>(3);
    square2<int>(3);
    square3<int>(3);

    return 0;
}