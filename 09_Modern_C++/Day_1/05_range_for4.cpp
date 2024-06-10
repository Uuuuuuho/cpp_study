#include <iostream>
#include <vector>

template<typename T>
class reverse_view
{
	T& c;
public:
	reverse_view(T& c) : c(c) {}

	auto begin(){ return c.rbegin() ;}
	auto end()	{ return c.rend() ;}
};

int main()
{
	std::vector<int> vec = {1,2,3,4,5};
	
	for(auto e : vec){
		std::cout << e << ", ";
	}
	std::cout << std::endl;

	reverse_view r_vec(vec);
	for(auto e : r_vec){
		std::cout << e << ", ";
	}
	std::cout << std::endl;

}

