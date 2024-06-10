// <Polynomial by Linked List>
#include <iostream>
#include <list>
#include <queue>
#include <iterator>
using namespace std;
template<class T> class Chain;//전방선언
template <class T>
class ChainNode {
	friend class Chain<T>;
private:
	T data;
	ChainNode<T> *link;
};
template <class T>
class Chain {
public:
	Chain() { first = 0; };//first를 0으로 초기화하는 생성자
	//체인 조작 연산들
	void InsertBack(const T&e);
private:
	ChainNode<T> *first;
};
template <class T>
void Chain<T>::InsertBack(const T&e){
	ChainNode<T>* last;
	if (first) {//공백이 아닌 체인
		last->link = new ChainNode<T>(e);
		last = last->link;
	}
	else first = last = new ChainNode<T>(e);//공백인 경우
}
struct Term {
	int coef;
	int exp;
	Term Set(int c, int e) { coef = c; exp = e; return *this; };
};
class Polynomial {
public:
	Polynomial operator+(Polynomial&);
	friend ostream&operator << (ostream&, Polynomial&);
	friend istream&operator >> (istream&, Polynomial&);
private:
	list<Term> poly;
//	Chain<Term> poly;
};
istream&operator >> (istream& is, Polynomial& p) {
	int coef; int exp; int noofterms;
	Term tmp;
	is >> noofterms;
	int i = 0;
	while (i < noofterms) {//입력이 남아 있으면
		is >> coef >> exp;//계수와 지수 입력
		p.poly.push_back(tmp.Set(coef, exp));
	//	p.poly.InsertBack(tmp.Set(coef, exp));
		i++;
	}
	return is;
}
ostream&operator << (ostream& os, Polynomial& p) {
	while (!p.poly.empty()) {//비지 않았으면
		if (p.poly.front().exp >0) {//지수가 0보다 크면
			if (p.poly.front().coef >0) {//계수가 0보다 크면
				if (p.poly.front().coef == 1) {//계수가 1이면
					os << "+ x^" << p.poly.front().exp;
				}
				else if (p.poly.front().coef != 1) {//계수가 1이 아니면
					os << "+ " << p.poly.front().coef << "x^" << p.poly.front().exp << " ";
				}
			}
			else if (p.poly.front().coef <0) {//계수가 1보다 작으면
				if (p.poly.front().coef == 1) {//계수가 -1이면
					os << "- x^" << p.poly.front().exp << " ";
				}
				else if (p.poly.front().coef != 1) {//계수가 -1이 아닌 음수이면
					os << "- " << p.poly.front().coef << "x^" << p.poly.front().exp;
				}
			}
		}
		else if (p.poly.front().exp == 0) {
			os << p.poly.front().coef << endl;
		}
		p.poly.pop_front();
	}
	os << endl;
	return os;	
}
Polynomial Polynomial::operator+(Polynomial& b) {//다항식 *this (a)와 b를 더해서 그 합을 반환한다.
	//iterator<Polynomial> iter;
	Polynomial a = *this;
	Term temp;
	Polynomial c;
	while (!a.poly.empty() || !b.poly.empty()) {//현재의 노드들은 널이 아님
		int sum = 0;
		if (a.poly.front().exp == b.poly.front().exp) {//지수가 같으면
			sum = a.poly.front().coef + b.poly.front().coef;
			c.poly.push_back(temp.Set(sum,a.poly.front().exp));
			a.poly.pop_front(); b.poly.pop_front();// 다음항으로 이동
		}
		else if (a.poly.front().exp < b.poly.front().exp) {//b의 계수가 더 크면
			c.poly.push_back(temp.Set(b.poly.front().exp,b.poly.front().coef));
			b.poly.pop_front();//b의 다음 항
		}
		else if (a.poly.front().exp > b.poly.front().exp) {//a의 계수가 더 크면
			c.poly.push_back(temp.Set(a.poly.front().exp, a.poly.front().coef));
			a.poly.pop_front();//a의 다음 항
		}
	}
	while (!b.poly.empty()) {
		c.poly.push_back(temp.Set(b.poly.front().exp, b.poly.front().coef));
		b.poly.pop_front();
	}
	return c;
}
int main() {
	Polynomial p1, p2, p3;
	cin >> p1 >> p2;
	p3 = p1 + p2;
	cout << p3;
}