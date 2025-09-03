#include <iostream>
#include <vector>

int main()
{
	std::vector<int> v1 = { 1,2,3,4,5 };
	std::vector<int> v2{ 1,2,3,4,5 };


	std::vector<int> v3(10, 2); /* 
                                    vector(int, int) constructor.
                                    Init 10 elements as 2.
                                */
	std::vector<int> v4{10, 2}; /* 
                                    vector(std::initializer_list)
                                    Init 2 elements as 10.
                                */

    std::cout << v3.size() << std::endl;    /* 10 */
    std::cout << v4.size() << std::endl;    /* 2 */

    // std::vector<int> v5 = 10;	/* Error: vector(size_type) 생성자는 explicit로 선언되어 있음.
    //    그 이유는 정수->컨테이너로의 암묵 변환을 방지하기 위함임.
    //    만약 explicit가 아니면 `std::vector<int> v = 10;` 같은 표현이
    //    실수로 컴파일되어 길이 10의 벡터가 생성될 수 있는데, 이는 의도치
    //    않은 버그를 유발할 가능성이 큼. 따라서 명시적(direct) 생성
    //    을 요구하는 편이 안전함.
    std::vector<int> v6 = {10}; /* 
                                    Ok.
                                    "vector(std::initializer_list)"
                                    is not explicit.
                                */
}




