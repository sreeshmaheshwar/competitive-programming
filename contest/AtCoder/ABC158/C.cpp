#include <algorithm>
#include <iostream>

int main() {
    int A, B;
    std::cin >> A >> B;
    for (int i = 0; i <= 13 * std::max(A, B); ++i) {
        if ((i * 2) / 25 == A && i / 10 == B) {
            std::cout << i;
            return 0;
        }
    }
    std::cout << -1;
    return 0;
}