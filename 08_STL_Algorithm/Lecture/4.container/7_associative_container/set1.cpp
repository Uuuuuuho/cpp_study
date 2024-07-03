#include <set>
#include <print>

/* 
    sequence container
    → 요소들이 삽입된 순서를 유지하면서 선형적으로 addressing 된 컨테이너
    → vector, dequeue, list, forward_list, array

    sequnce container에 100개의 요소가 있을때 값을 검색하려면
    → 평균 50번의 이동과 비교가 필요하다.

    좀 더 빠른 방법은 없나?
    → tree, hash 등 “검색에 최적화된 다른 자료구조” 사용
    → “associative container” 사용

    associative continer
        “key“ 값을 가지고, “value”를 보관하기 때문에 붙여진 이름

    종류

    | set
    multiset | tree(red-black) | key만 보관 |
    | --- | --- | --- |
    | map
    multimap | tree(red-black) | key-value쌍을 보관 |
    | unordered_set
    unordered_multiset | hash | key만 보관 |
    | unordered_map
    unordered_multimap | hash | key-value 쌍을 보관 |

    C++ 표준에서는 container 구현 방식을 강제하지 않으므로 “STL 구현에 따라 다른 자료구조를 사용할 수 있음.” (하지만 대부분 구현은 RB Tree와 Hash 사용)

    std::set
    요소 삽입
    → 새로운 요소는 “root부터 크비를 비교”해서 규칙에 맞도록 삽입되어야함.
    → isnert, emplace, insert_range(C++23)으로만 요소 삽입 가능.
    → push_back, push_front 등 멤버 함수는 제공되지 않음

    set은 요소의 중복을 허용하지 않음
    → 삽입할 요소가 이미 존재한다면 실패
    → insert 반환값(std::pair (std::set<int>>::iterator, bool))을 통해서 실패를 전달

*/

int main()
{
	std::set s{ 50, 30, 70, 40, 60 };

	// #1. 요소 삽입 방법	
	s.insert(20);
	s.emplace(80);	
//	s.push_back(20);	// error
//	s.insert_range(std::vector{45, 55});	// C++23


	// 2. 중복을 허용하지 않음.
	auto ret = s.insert(40);

	if ( ret.second == false )
		std::println("insert fail");	
}