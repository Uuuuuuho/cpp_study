template <typename T>
void fn(T a) {

}

// template을 사용하지 않기 때문에 코드를 생성하지는 않는데, 컴파일러에게 코드 생성하기를 요청하는 방법
template void fn<int > (int);
template void fn< > (double);
template void fn(char);

template <class T>
class Type {
    void mf1() {}
    void mf2() {}
};
// class template에 대한 explicint instantiation
template class Type<int>;
// class 내부의  member functionㅇp 대한 explicit instantiation
template void Type<double>:mf1();

int main() {

}