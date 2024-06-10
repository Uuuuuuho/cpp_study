#include<iostream>
#include<fstream>
#include"maze.h"
using namespace std;
void getdata(istream&, int&, int&);
void Path(int, int);
int main(int argc, char* argv[]) {
	int m =9, p =9;
	maze maze[m][p] = {
		{0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 0},
		{1, 0, 0, 0, 0, 0, 0, 0, 1},
		{0, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 0},
		{1, 0, 0, 0, 0, 0, 0, 0, 1},
		{0, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0}
	}
	Path(m, p);	
}