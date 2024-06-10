#include <vector>

template<typename T>
auto mybegin(T& c) {
    return c.begin();
}

int main()
{
    std::vector<int> v = {1,2,3};
    int x[3] = {1,2,3};

    auto p1 = mybegin(v);
    auto p2 = mybegin(x);
}