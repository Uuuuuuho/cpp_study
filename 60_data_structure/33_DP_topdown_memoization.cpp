#include <iostream>
#include <vector>

int fibonacci_top_down(int n, std::vector<int>& memo) {
    if (n <= 1) {
        return n;
    }

    if (memo[n] == -1) {
        memo[n] = fibonacci_top_down(n - 1, memo) + fibonacci_top_down(n - 2, memo);
    }

    return memo[n];
}

int fibonacci(int n) {
    std::vector<int> memo(n + 1, -1);
    return fibonacci_top_down(n, memo);
}

int main() {
    std::cout << fibonacci(6) << std::endl;   // Output: 8
    return 0;
}
