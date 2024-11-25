
// class Object {
//     int value;
// public:
//     void mf() {
//         *value = 10; // error. Pointer에 value를 assign.
//     }
// };

template <typename T>
class Object {
    T value;
public:
    void mf() { // Lazy instantiation. 
    // 컴파일러가 함수를 사용하기 전에 class template의 함수를 코드로 생성하지 않음.
        *value = 10;
    }
};

int main() {
    Object obj;
}