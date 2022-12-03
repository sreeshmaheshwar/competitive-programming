#include <iostream>

int main() {
    int n;
    std::cin >> n;
    for (int i = 0, prev_s = 0, curr_s; i < n; ++i, prev_s = curr_s) {
        std::cin >> curr_s;
        std::cout << curr_s - prev_s << " ";
    }
}