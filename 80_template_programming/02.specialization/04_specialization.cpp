/* 의도적으로 구현체를 빼서 특ㅈㅓㅇ 부분 특수화에 대해서만 사용하기 위한 기법.
 * primary template을 선언만 제공하면 됨.
 * 고급 template programming에서 사용됨.
 */
template <typename T, int N> // <= primary template
struct Object;

template <typename T>
struct Object <T, 1> {

};

template <typename T>
struct Object<T, 2> {
    
};

int main() {
    Object<int, 1> obj1;
    Object<int, 2> obj2;
    Object<int, 3> obj3;
}