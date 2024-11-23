#include <iostream>
#include <array>

template<typename T>
void print_arr(const T& arr) {
    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    // 마치 C에서의 배열처럼 {}을 통해 배열을 정의할 수 있음. 
    std::array<int, 5> arr = {1, 2, 3, 4, 5};
    // int arr[5] = {1, 2, 3, 4, 5};와 동일
    // "{}"에 대한 문법은 uniform initialization을 참고해볼 것.

    /* 
     * std::arr는 런타임에 동적으로 할당되는 컨테이너가 아님.
     * 동적으로 메모리를 할당받지 않고 nontype template으로 array의
     * 사이즈를 결정지음. 즉, std::array<data type, size>로
     * array의 사이즈는 선언시점에 걸졍됨.
     */

    // for (int i = 0; i < arr.size(); i++) {
    //     std::cout << arr[i] << " ";
    // }

    // std::cout << std::endl;
    print_arr(arr);
}