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
    // 1. 요소의 개수 구하기
    // const std::size_t cnt_element = last - first;   // data structure 따라서 incorrectable...   
    const std::size_t cnt_element = std::distance(first,last);   // correct method of counting elements

    if (cnt_element==0) return 0;

    // 2. 스레드 개수 결정
    const std::size_t min_per_thread = 25;  // one thread가 최소 25개 처리.
    const std::size_t max_thread = (cnt_element + min_per_thread - 1)/min_per_thread;

    std::size_t hw_threads = std::thread::hardware_concurrency();
                                    // 현재 PC의 CPU core 개수 구하기.
    if (hw_threads==0) hw_threads = 2;

    const std::size_t cnt_threads = std::min(hw_threads, max_thread);

    printf("elements: %d, core #: %d, cnt_threads: %d, max_threads: %d\n", 
                cnt_element, hw_threads, cnt_threads, max_thread);
    // 3. 스레드 한개당 처리할 데이터의 개수
    const std::size_t block_size = cnt_element/cnt_threads;
    // ===================================
    // 현재 RT는 int
    // 스레드 개수를 "24개"라고 할때
    // 23개의 결과를 담은 vector와 23개의 스레드 객체를 관리할 vector
    // 1개는 main thread
    std::vector<RT>             result_vector(cnt_threads);
    std::vector<std::thread>    thread_vector(cnt_threads-1);

    IT block_start = first;

    for(int i = 0; i < (cnt_threads-1); i++){
        IT block_end = block_start;
        std::advance(block_end,block_size);

        // 새로운 스레드로 [block_start, block_end) 구간의 합을 구해서
        // result_vector[i]에 넣는다.
        thread_vector[i] = std::thread(sum<IT,RT>,
                                        block_start, block_end,
                                        std::ref(result_vector[i]));    // thread의 function parameter로 주기 때문에 std::ref로 넘겨줘야함.
        block_start = block_end;
    }
    // 마지막 블럭은 주스레드가 처리
    // 스레드를 만드는 것이 아닌 그냥, sum 호출이므로 std::ref()가 필요없음.
    sum(block_start, last, result_vector[cnt_threads-1]);

    std::for_each(thread_vector.begin(), thread_vector.end(),
                        [](std::thread& t){t.join();});

    return std::accumulate(result_vector.begin(), result_vector.end(), init);
}

int main()
{
    init();

    // 핵심 : "parallel_sum" 의 구현을 완벽히 이해해 보세요.
    int s = parallel_sum(v.begin(), v.end(), 0);

    std::cout << s << std::endl;
}