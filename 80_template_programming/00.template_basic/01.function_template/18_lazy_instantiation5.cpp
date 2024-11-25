template <typename T>
void fn(T value) {
    // if(false) // false문이기 때문에 실행은 안되지만 "인스턴스화"에는 포함된다.
    if constexpr (false)
        *value = 10; 
}

int main() {
    int n = 10;
    fn(n);
}