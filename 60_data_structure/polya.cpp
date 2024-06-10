#include<iostream>
#include"polya.h"
using namespace std;
Polynomial::Polynomial():capacity(4), terms(0)
{
	termArray =new Term[capacity];
}
istream&operator>>(istream& is, Polynomial& p) {
	int noofterms; float coef; int exp;
	is >> noofterms;
	for (int i =0; i < noofterms; i++) {
		is >> coef >> exp;
		p.NewTerm(coef, exp);
	}
	return is;
}
ostream&operator<<(ostream& os, Polynomial& p) {
	for (int i =0; i < p.terms; i++) {
		if (p.termArray[i].exp >0) {
			if (p.termArray[i +1].coef >0) {
				if (p.termArray[i].coef ==1) {
					os <<"x^"<< p.termArray[i].exp <<" "<<"+";
				}
				else if (p.termArray[i].coef !=1) {
					os << p.termArray[i].coef <<"x^"<< p.termArray[i].exp <<" "<<"+";
				}
			}
			else if (p.termArray[i +1].coef <0) {
				if (p.termArray[i].coef ==1) {
					os <<"x^"<< p.termArray[i].exp <<" ";
				}
				else if (p.termArray[i].coef !=1) {
					os << p.termArray[i].coef <<"x^"<< p.termArray[i].exp <<" ";
				}
			}
		}
		else if (p.termArray[i].exp ==0) os << p.termArray[i].coef <<endl;
		else os <<"";
	}
	return os;
	cout<<endl;
}
void Polynomial::NewTerm(const float theCoeff, const int theExp) {
	if (terms == capacity) {
		capacity *=2;
		Term *temp =new Term[capacity];
		for (int i =0; i < terms +1; i++)
			temp[i] = termArray[i];
		delete[] termArray;
		termArray = temp;
	}
	termArray[terms].coef = theCoeff;
	termArray[terms++].exp = theExp;
}
Polynomial Polynomial::operator+(Polynomial& b) {
	Polynomial c;
	int aPos =0, bPos =0;
	while((aPos < terms)||(bPos < b.terms))
		if (termArray[aPos].exp == b.termArray[bPos].exp) {
			float t = termArray[aPos].coef + b.termArray[bPos].coef;
			if (t)c.NewTerm(t, termArray[aPos].exp);
			aPos++; bPos++;
		}
		else if (termArray[aPos].exp < b.termArray[bPos].exp) {
			c.NewTerm(b.termArray[bPos].coef, b.termArray[bPos].exp);
			bPos++;
		}
		else {
			c.NewTerm(termArray[aPos].coef, termArray[aPos].exp);
			aPos++;
		}
		for (; aPos < terms; aPos++)
			c.NewTerm(termArray[aPos].coef, termArray[aPos].exp);
		for (; bPos < terms; bPos++)
			c.NewTerm(termArray[bPos].coef, termArray[bPos].exp);
		return c;
}