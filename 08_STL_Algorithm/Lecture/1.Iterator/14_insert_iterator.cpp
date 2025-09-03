/**
 * 개요:
 *  - 이 예제는 C++ 표준 라이브러리의 "삽입 반복자(insert iterator)"를 사용하여
 *    컨테이너에 요소를 추가하는 방법을 보여준다.
 *  - std::back_insert_iterator 를 사용해 컨테이너의 끝에 요소를 추가하고,
 *    std::copy 와 같은 범용 알고리즘과 결합하여 요소 복사를 수행한다.
 *
 * 주요 설명:
 *  - 삽입 반복자란?
 *      삽입 반복자는 일반 반복자와 달리 컨테이너에 직접 요소를 "삽입"하도록
 *      동작하는 출력(output) 반복자이다. <iterator> 헤더에서 제공되며
 *      대표적으로 다음 세 가지가 있다:
 *        - std::back_insert_iterator<C>   : 컨테이너의 push_back 호출로 추가
 *        - std::front_insert_iterator<C>  : 컨테이너의 push_front 호출로 추가
 *        - std::insert_iterator<C>        : 지정된 위치에 insert 호출로 추가
 *
 *  - 왜 삽입 반복자가 필요한가?
 *      표준 알고리즘(예: std::copy, std::transform 등)은 "출력 반복자"를 통해
 *      결과를 쓴다는 전제 하에 설계되어 있다. 그러나 직접 컨테이너에
 *      요소를 추가하려면 반복문을 쓰거나 컨테이너의 멤버 함수(push_back 등)를
 *      직접 호출해야 한다. 삽입 반복자는 이 둘을 연결해주는 어댑터 역할을 한다:
 *        - 알고리즘이 기대하는 출력 반복자 인터페이스(operator=, ++ 등)를 제공하고,
 *        - 내부적으로는 컨테이너의 적절한 삽입 연산(push_back, push_front, insert)을 호출한다.
 *      따라서 코드를 더 범용적이고 재사용 가능하게 만들며, 직접 반복문을
 *      작성하지 않아도 알고리즘을 통해 컨테이너에 안전하게 요소를 추가할 수 있다.
 *
 *  - 사용상의 주의사항:
 *      - std::back_insert_iterator 를 쓰려면 대상 컨테이너가 push_back 멤버를
 *        제공해야 한다(예: std::vector, std::deque, std::list 등).
 *      - std::front_insert_iterator 는 push_front 를 제공하는 컨테이너에만 사용.
 *      - std::insert_iterator 는 특정 삽입 위치를 필요로 하며, 해당 컨테이너의
 *        insert 멤버를 사용한다.
 *      - 삽입 반복자는 컨테이너의 삽입 비용(복사/이동, 재할당, 연결 비용 등)에
 *        영향을 받는다. 즉 성능 특성은 기저 컨테이너의 삽입 복잡도에 따름.
 *
 * 예시 동작(개념적):
 *  - list<int> s = {1,2,3,4,5};
 *  - s.push_back(10);                        // 직접 삽입 예
 *  - auto p = back_insert_iterator(s);      // s에 대한 back_insert_iterator 생성
 *  - *p = 20;                                // 내부적으로 s.push_back(20) 호출
 *  - int x[] = {1,2,3,4,5};
 *  - std::copy(x, x+5, p);                  // x의 원소들이 s의 끝에 순차적으로 추가됨
 *
 * 출력:
 *  - 위 동작 이후 s의 내용은 원래 원소들에 이어 10, 20, 그리고 x의 모든 요소들이
 *    추가된 상태가 된다.
 *
 * 결론:
 *  - 삽입 반복자는 표준 알고리즘과 컨테이너 삽입 연산을 효율적으로 연결해주는
 *    유용한 도구이다. 직접 루프를 작성하지 않고도 범용 알고리즘으로 컨테이너를
 *    채울 수 있게 해주므로 코드의 간결성 및 재사용성을 높인다.
 */
#include <iostream>
#include <list>
#include <iterator>
using namespace std;

/* 핵심 정리
    1. 컨테이너 요소를 추가하는 방법
        - 멤버함수 사용(push_xxx/emplace_xxx/insert)
        삽입 반복자(insert iterator)
    2. 삽입 반복자
        - <iterator> 헤더
        - 컨테이너 요소를 삽입(추가)할 때 사용하는 반복자
        3가지 종류 (전방 삽입, 후방 삽입, 임의 삽입) 제공
    3. 기본 모양
        - back_insert_iterator<컨테이너 클래스 이름> p (컨테이너 객체);
    4. copy와 같은 STL 알고리즘을 사용해서 컨테이너에 요소를 추가할 수 있다.
*/

int main(int argc, char** argv)
{
    list<int> s = {1,2,3,4,5};

    s.push_back(10);

    back_insert_iterator<list<int>> p(s);

    *p = 20; // s.push_back(20);


    int x[5] = {1,2,3,4,5};
    // for(int i = 0; i < 5; i++)
    //     s.push_back(x[i]);

    copy(x, x+5, p);

    for (auto& n: s)
        cout << n << endl;
}