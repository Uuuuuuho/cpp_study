// <Equivalnce>
//기존 버전
#if 0
#include <iostream>
#include <fstream>
using namespace std;
class Enode
{
friend void Equivalence();
public:
	Enode(int d = 0, Enode* l = 0)
	{	data = d; link = l;	}
private:
		int data;
		Enode *link;	
};
void Equivalence()
{
	ifstream inFile("equiv.in", ios::in);
	if (!inFile) throw "Cannot open input file";
	int i, j, n;
	inFile >>  n;
	Enode **first = new Enode*[n];
	bool *out = new bool[n];
	fill(first, first + n, (Enode *)0);
	fill(out, out + n, false);	
	//1단계. input equivalence pairs
	inFile >> i >> j;
	while (inFile.good())
	{
		first[i] = new Enode(j, first[i]);
		first[j] = new Enode(i, first[j]);
		inFile >> i >> j;
	}
	//2단계. output equivalence classes
	for (i = 0; i < n; i++)
	{
		if (!out[i])
		{
			cout << endl << "A new class: " << i;
			out[i] = true;
			Enode *x = first[i];
			Enode *top = 0;
			while (1)
			{
				while (x)
				{
					j = x->data;
					if (!out[j])
					{
						cout << "," << j; out[j] = true;
						Enode *y = x->link;
						x->link = top; top = x;
						x = y;
					}
					else
						x = x->link;
				}
				if (!top) break;
				x = first[top->data];
				top = top->link;
			}
		}
		cout << endl;
	}
	for ( i = 0; i < n; i++)
		while (first[i])
		{
			Enode *delnode = first[i];
			first[i] = delnode->link;
			delete delnode;
		}
	
	delete[] first; delete[] out;
}
int main()
{
	Equivalence();
	return 0;
}
#endif
//★★수정버전★★
#if 1
#include <iostream>
#include <fstream>
#include <stack>
#include <list>
using namespace std;
void Equivalance()
{
	ifstream inFile("equiv.in", ios::in);
	if (!inFile) throw "Cannot open input file";
	int i, j, n;
	inFile >> n;	//read in number of objects;
	//변수 초기화
	list<int> *lst = new list<int>[n];
	bool *out = new bool[n];
	//use STL function fill to initialize
	fill(out, out + n, false);
	//1단계. input equivalance pairs
	inFile >> i >> j;
	while (inFile.good())	//check end of file
	{
		lst[i].push_front(j);	//i째 리스트의 앞에 j가진 노드 추가
		lst[j].push_front(i);	//j째 리스트의 앞에 i가진 노드 추가
		inFile >> i >> j;
	}
	//2단계. output equivalance classes
	stack<int> pstack;
	for ( i = 0; i < n; i++)
	{
		if (out[i])
			continue;
		cout << endl << "A new class: " << i; 
		out[i] = true;
		while (!lst[i].empty())
		{
			j = lst[i].front();
			lst[i].pop_front();
			if (!out[j])
			{
				cout << "," << j;
				out[j] = true;
				pstack.push(j);
			}
		}
		while (!pstack.empty())
		{
			int s = pstack.top(); pstack.pop();
			while (!lst[s].empty())
			{
				j = lst[s].front(); lst[s].pop_front();
				if (!out[j])
				{
					cout << "," << j;
					out[j] = true;
					pstack.push(j);
				}
			}
		}
	}
	cout << endl;
	for ( i = 0; i < n; i++)
	{
		lst[i].clear();
	}
	delete[] out;
}
int main() 
{ 
	Equivalance(); 
	return 0;
}
#endif