template <typename T> class list {

};

/* template paramter의 종류
 * 1. type
 * 2. non-type
 * 3. template
 */
template <typename T, int N, template <typename> class C> // template 파라미터로 다시 template을 보내주기때문에 type이 아니라 template을 넘겨줘야함.
class Object {

};

int main() {
    // Object<int, 3, list<int>> obj1; // error
    Object<int, 3, list> obj1;
}