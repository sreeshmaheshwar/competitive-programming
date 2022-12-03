#include <bits/stdc++.h>

std::vector<std::pair<int64_t, int64_t>> prime_factorise(int64_t n) {
    std::vector<std::pair<int64_t, int64_t>> ret;
    for (int i = 2; 1LL * i * i <= n; ++i) {
        if (n % i == 0) {
            int count = 0;
            while (n % i == 0) n /= i, count++;
            ret.emplace_back(i, count);
        }
    }
    if (n > 1) ret.emplace_back(n, 1);
    return ret;
}

int main() {
    int64_t k;
    std::cin >> k;
    auto prime_factors = prime_factorise(k);

    auto factorial_is_mutliple = [&](int64_t n) -> bool {
        for (auto [factor, count] : prime_factors) {
            for (int64_t i = factor; i <= n; i *= factor) count -= n / i;
            if (count > 0) return false;
        }
        return true;
    };

    int64_t low = 1, high = k + 1;
    while (low < high) {
        int64_t mid = (low + high) / 2;
        (factorial_is_mutliple(mid) ? high = mid : low = mid + 1);
    }
    std::cout << low;
}