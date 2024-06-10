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
    for (int i = 0; i < sz; ++i)
    {
        v.push_back(i);
    }
}

template<typename IT, typename RT>
void sum(IT first, IT last, RT& result)
{
    result = std::accumulate(first, last, result);
}

template<typename IT, typename RT>
RT parallel_sum(IT first, IT last, RT init)
{
    // 1. ����� ���� ���ϱ�
    // const std::size_t cnt_element = last - first;   // data structure ���� incorrectable...   
    const std::size_t cnt_element = std::distance(first,last);   // correct method of counting elements

    if (cnt_element==0) return 0;

    // 2. ������ ���� ����
    const std::size_t min_per_thread = 25;  // one thread�� �ּ� 25�� ó��.
    const std::size_t max_thread = (cnt_element + min_per_thread - 1)/min_per_thread;

    std::size_t hw_threads = std::thread::hardware_concurrency();
                                    // ���� PC�� CPU core ���� ���ϱ�.
    if (hw_threads==0) hw_threads = 2;

    const std::size_t cnt_threads = std::min(hw_threads, max_thread);

    printf("elements: %d, core #: %d, cnt_threads: %d, max_threads: %d\n", 
                cnt_element, hw_threads, cnt_threads, max_thread);
    // 3. ������ �Ѱ��� ó���� �������� ����
    const std::size_t block_size = cnt_element/cnt_threads;
    // ===================================
    // ���� RT�� int
    // ������ ������ "24��"��� �Ҷ�
    // 23���� ����� ���� vector�� 23���� ������ ��ü�� ������ vector
    // 1���� main thread
    std::vector<RT>             result_vector(cnt_threads);
    std::vector<std::thread>    thread_vector(cnt_threads-1);

    IT block_start = first;

    for(int i = 0; i < (cnt_threads-1); i++){
        IT block_end = block_start;
        std::advance(block_end,block_size);

        // ���ο� ������� [block_start, block_end) ������ ���� ���ؼ�
        // result_vector[i]�� �ִ´�.
        thread_vector[i] = std::thread(sum<IT,RT>,
                                        block_start, block_end,
                                        std::ref(result_vector[i]));    // thread�� function parameter�� �ֱ� ������ std::ref�� �Ѱ������.
        block_start = block_end;
    }
    // ������ ���� �ֽ����尡 ó��
    // �����带 ����� ���� �ƴ� �׳�, sum ȣ���̹Ƿ� std::ref()�� �ʿ����.
    sum(block_start, last, result_vector[cnt_threads-1]);

    std::for_each(thread_vector.begin(), thread_vector.end(),
                        [](std::thread& t){t.join();});

    return std::accumulate(result_vector.begin(), result_vector.end(), init);
}

int main()
{
    init();

    // �ٽ� : "parallel_sum" �� ������ �Ϻ��� ������ ������.
    int s = parallel_sum(v.begin(), v.end(), 0);

    std::cout << s << std::endl;
}