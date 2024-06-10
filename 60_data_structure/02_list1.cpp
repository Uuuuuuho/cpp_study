// <Linked List>

#include <iostream>
using namespace std;
/*
class ThreeLetterChain;
class ThreeLetterNode {
	friend class ThreeLetterChain; //HAS-ThreeLetterChain ThreeLetterNode
private:
	char data[3];
	ThreeLetterNode* link;
};
class NodeA {
private:
	int data1;
	char data2;
	float data3;
	NodeA* linka;
	NodeB* ilnkb;
};
class NodeB {
private:
	int data;
	NodeB* link;
};
*/
/*
주소 = left value
저장값 = right value
보통 point는 right value(저장값)를 가리키지만 배정문의 좌변에 위치할 때는 left value(주소)이다.
- 반복자(iterator)는 컨테이너 클래스의 모든 원소를 순회하는데 사용되는 객체이다.
컨테이너 클래스 C의 반복자가 필요한 이유
1. C에 포함된 모든 정수를 출력하라
2. C에 포함된 모든 정수의 최대, 최소, 평균, 중간 값을 계산하라
3. C에 포함된 모든 정수의 합, 곱, 제곱의 합을 계산하라
4. C에 포함된 모든 정수 중에서 어떤 성질 P를 만족시키는 것을 검색하라
5. 어떤 함수 f(x)의 값이 최대가 되는 C의 원소 x를 찾으라
이러한 문제들에 대한 해답을 얻기 위해서는 컨테이너 클래스의 모든 원소를 순회해야 한다
*/
//체인의 템플릿 정의
class Chain;
template <class T>
struct ChainNode {
	T data;
	ChainNode<T>*link;
};
//Chain을 위한 전방 반복자
template <class T>
class ChainIterator {
public:
	//생략된 전방 반복자에 대해 C++은 타입 정의를 요구한다.
	
	// 생성자
	ChainIterator(ChainNode<T>* startNode =0) { current = startNode; }
	//역참조 연산자
	T&operator*() const {return current->data;}
	T*operator->()const { return&current->data;}
	
	//증가
	ChainIterator&operator++()//사전 증가
	{
		current = current->link; return*this;
	}
	ChainIterator operator++(int) {
		ChainIterator old =*this;
		current = current->link;
		return old;
	}
	//동등 검사
	bool operator!= (const ChainIterator right) const { return current != right.current; }
	bool operator== (const ChainIterator right) const { return current == right.current; }
private:
	ChainNode<T>* current;
};
//리스트 끝에 노드 삽입
template <class T>
void Chain<T>::InsertBack(const T& e) {
	if(first){//공백이 아닌 체인
		last->link =new ChainNode<T>(e);
		last = last->link;
	}
	else first = last =new ChainNode<T>(e);
}
//두 체인의 접합(concetanate)
template <class T>
void Chain<T>::Concatenate(Chain<T>&b) {//b는 *this 끝에 연결
	if (first)(last->link = b.first; last = b.last;)
	else first = b.first; last = b.last;
	b.first = b.last =0;
}
//리스트의 역순서화
template <class T>
{//체인 (a1,....,an)이 (an,....,a1)으로 역순으로 된다.
	ChainNode<T>*current = first,
	*previous = 0;//previous는 current를 따라간다.
	while (current) {
		ChainNode<T>*r = previous;
		previous = current;
		current = current->link;
		previous->link = r;
	}
	last = first;
	first = previous;
}