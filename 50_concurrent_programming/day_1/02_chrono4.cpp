#include <iostream>
#include <chrono>
#include <string>

// time_point : "기준 시각 + 경과된 시간"
//              ex) 0년1월 1일 이후에 1000000000초 지났다
// 
// epoch_time : "1970년 1월 1일" 이후 경과된 시간
int main()
{
    // 현재 시간을 구하는 코드
    std::chrono::system_clock::time_point tp = 
                                std::chrono::system_clock::now();
                                            // static 멤버함수 now()

    // 1970년 1월 1일 0시 기준.
    std::chrono::nanoseconds ns = tp.time_since_epoch();

    std::cout << ns.count() << std::endl;

    std::chrono::hours h = 
        std::chrono::duration_cast<std::chrono::hours>(ns);
    
    std::cout << h.count() << std::endl;

    // time_point => 문자열로 변환.
    // 1. time_point => time_t 로 변경
    time_t t = std::chrono::system_clock::to_time_t(tp);

    // 2. time_t 를 문자열로 변경
    char s[256] = { 0 };
    ctime_s(s, 256, &t);

    std::cout << s << std::endl;

}