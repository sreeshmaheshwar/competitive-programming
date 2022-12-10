#include <algorithm>
#include <iostream>
#include <vector>

const int MAX_BIT = 29;

int solve(const std::vector<int>& a, int bit) {
    if (bit < 0) return 0;
    std::vector<std::vector<int>> b(2);
    for (auto& x : a) b[x >> bit & 1].push_back(x);
    if (b[0].empty() || b[1].empty()) return solve(a, bit - 1);
    return std::min(solve(b[0], bit - 1), solve(b[1], bit - 1)) | (1 << bit);
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto& x : a) std::cin >> x;
    std::cout << solve(a, MAX_BIT) << std::endl;
}