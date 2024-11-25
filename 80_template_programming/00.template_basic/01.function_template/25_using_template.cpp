#include <unordered_set>

/* 타입에 대한 별징(alias)를 만드느 방법
 * C style: typedef std::unordered_set<int> SET;
 * C++ style: using SET = std::unordered_set<int>;
 */
typedef std::unordered_set<int> SET;
using SET = std::unordered_set<int>;

/* 타입이 아닌 템플릿에 대한 별칭을 만들 수 없을까?
 * type alias - std::unordered_set<int> → SET
 * template alias - std::unordered_set<int>
 */
template <typename T>
using SET = std::unordered_set<T>;

int main() {

    // std::unordered_set<int> s1;

    // SET s1;
    SET<int> s1;
    SET<double> s2;
}