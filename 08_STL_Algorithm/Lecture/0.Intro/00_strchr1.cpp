#include <iostream>
#include <cstring>

/* 
1. 구간 종료 조건을 함수 인자로 전달
    - 시작 주소와 검색할 요소의 개수를 전달
    - 시작주소와 마지막 요소의 주소를 전달 => STL이 사용하는 방식
2. 검색대상
    - 시작 주소가 가리키는 곳은 검색에 포함
    - 마지막 주소가 가리키는 곳은 검색에 포함되지 않음
    - 반 개행 구간
    - [first, last)로 표기
    - 전체 문자열을 검색하려면 estrchr(s, s + strlen(s), 'c')
3. 개선점
    - 모든 타입의 배열에 대해 적용이 어려운가?
 */

char* estrchr(char* first, char* last, char val){
    while (first != last && *first != val)
        ++first;

    return first == last ? 0 : first;
}

int main()
{
    char s[] = "abcdefg";
    char *p = estrchr(s, s+10, 'c');

    if (p == 0)
        std::cout << "fail" << std::endl;
    else
        std::cout << "success : " << *p << std::endl;
}