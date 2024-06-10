#include <iostream>
#include <thread>


void foo(int a, double d) {}

struct Machine
{
    void Run(int a, double d) {}
};

struct Work
{
    void operator()(int a, double b) const {}
};

// std::thread �� �����ڸ� ������ ���ô�.
class mythread
{
public:
    // ��Ģ 1. ������ ���ڴ� �ݵ�� "()" �� ȣ�Ⱑ���� ���� ���޵Ǿ�� �մϴ�.
    
    template<typename T, typename ... Types >
    mythread(T&& func, Types&& ... args)
    {
        // 1. �� OS�� �ý��� call �� ����ؼ� ������ ����
        // 2. ������ �����尡 ������ ���ڷ� ���޵� �Լ� ����.

        // �Ʒ� ó�� �ϸ� func �� "�Ϲ��Լ�", "�Լ���ü" �� �˴ϴ�.
        // ��� �Լ��� �ȵ˴ϴ�.
        // func( std::forward<Types>(args)... ); // ���ο� �����尡 �����ϵ���.. �ڵ� �ۼ�..
        
        // �Ʒ� ó�� �ϸ� ��� �Լ��� �˴ϴ�.
        std::invoke(func, std::forward<Types>(args)...);
    }
};
int main()
{
    mythread t1(&foo, 3, 3.4);

    Work w;
    mythread t2(w, 3, 3.4); // w(3, 3.4) => w.operator()(3, 3.4)
//  mythread t2(&w, 3, 3.4);// &w �� Work* �Դϴ�. ()�� ȣ��ȵ˴ϴ�.

    Machine m;
    mythread t3(&Machine::Run, &m, 3, 3.4);

    // C���  : �Լ��� �Լ� ������ �ڿ��� ()�� ���ϼ� �ֽ��ϴ�.
    //C++��� : �Լ�, ()�����ڸ� �������� ��ü, �Լ������� ���� ��
    //         ()�� ���ϼ� �ֽ��ϴ�.

}






struct FUNC
{
    int& value;
    FUNC(int& r) : value(r) {}

    void operator()() const
    {
        value = 10;
    }
};