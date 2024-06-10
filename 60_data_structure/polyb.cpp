#include<iostream>
#include"polyb.h"
using namespace std;
Polynomial::Polynomial() :capacity(4), terms(0)
{
	termArray =new Term[capacity];
}
istream&operator>> (istream& is, Polynomial& p) {
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
				else if (p.termArray[i].coef ==-1) {
					os <<"-"<<"x^"<< p.termArray[i].exp <<" ";
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
	while ((aPos < terms) || (bPos < b.terms))
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
Polynomial Polynomial::operator*(Polynomial& b) {
	Polynomial c, d;
	int aPos =0, bPos =0;
	while (aPos < terms) {
		while (bPos < b.terms) {
			float n = termArray[aPos].coef * b.termArray[bPos].coef;
			int C = termArray[aPos].exp + b.termArray[bPos].exp;
			if (n)c.NewTerm(n, C);
			bPos++;
		}
		aPos++;
		bPos =0;	
		
	}
	for (int i =0; i < c.terms; i++) {
		int j = i;
		for (int k = i +1; k < c.terms; k++)
			if (c.termArray[k].exp > c.termArray[j].exp)j = k;
		d.termArray[i] = c.termArray[j];
		c.termArray[j] = c.termArray[i];
		c.termArray[i] = d.termArray[i];
	}
	d = c;
	for (int i =0; i < c.terms; i++) {
		for (int j =0; j < d.terms && i != j; j++) {
			if (c.termArray[i].exp == d.termArray[j].exp) {
				c.termArray[i].coef = c.termArray[i].coef + d.termArray[j].coef;
				c.termArray[j].coef, c.termArray[j].exp =-1;
			}
		}
	}
	return c;
}