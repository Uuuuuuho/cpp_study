// std::list의 내부구조
template <typename T, typename Ax = std::allocator<T>>
class list {
public:
    using value_type = T; // 핵심
    //...
};

int main() {
    std::list<int> s = {1,2,3};

    /* list의 타입이 int면 당연히 int n으로 작성하면되지만
     * 어떤 타입이 오는지 모르는 경우를 위한 인터페이스가 "value_type"
     */
    std::list<int>::value_type n = s.front();
                    // int n = s.front();
}