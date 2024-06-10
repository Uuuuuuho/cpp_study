#include <thread>
#include <numeric>
#include <algorithm>
#include <functional>
#include <vector>
#include <iostream>

constexpr std::size_t sz = 10000;
std::vector<int> v;

void init()
{
    for (int i = 0; i < sz; i++){
        v.push_back(i);
    }
}

// ������ ���� ���ϴ� �Լ�.
// [first,last)�� ��� ����� ���� 3��° ���ڿ� ��� �Լ�
template<typename IT, typename RT> 
void sum(IT first, IT last, RT& result)
{
    result = std::accumulate(first, last, result);
}

int main()
{
    init();

    int s = 0;
    // sum(v.begin(), v.end(), s); // �� �����尡 ȣ��

    // ���ο� ������� sum ����
    // std::thread t(sum, v.begin(), v.end(), std::ref(s));
                // error
                // sum�� ���� ȣ���� ���� �ƴϹǷ� ���ø� ���� �߷� �ȵ�
    
    // std::thread t(sum<std::vector<int>::iterator, int>, v.begin(), v.end(), std::ref(s));
    std::thread t(sum<std::vector<int>::iterator, int>, v.begin(), v.end(), std::reference_wrapper<int>(s));

    t.join();

    std::cout << s << std::endl;
}
