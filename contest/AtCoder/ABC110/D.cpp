#include <cassert>
#include <iostream>
#include <vector>
#include <utility>

namespace mod_operations {
    const int MOD = 1e9 + 7;
    
    int multiply(int a, int b) {
        return ((long long) a * b) % MOD;
    }

    int pow(int a, int b) {
        int ret = 1;
        while (b) {
            if (b & 1) ret = multiply(ret, a);
            a = multiply(a, a);
            b >>= 1;
        }
        return ret;
    }

    int inverse(int a) { 
        return pow(a, MOD - 2); 
    }
}

const int MAX_FACTORIAL = 1e6;
int factorial[MAX_FACTORIAL + 1];
int inverse_factorial[MAX_FACTORIAL + 1];

void precompute_factorials() {
    factorial[0] = inverse_factorial[0] = 1;
    for (int i = 1; i <= MAX_FACTORIAL; ++i) {
        factorial[i] = mod_operations::multiply(i, factorial[i - 1]);
        inverse_factorial[i] = mod_operations::inverse(factorial[i]);
    }
}

int binomial_coefficient(int a, int b) {
    assert(0 <= a && a <= MAX_FACTORIAL);
    assert(0 <= b && b <= a);
    return mod_operations::multiply(mod_operations::multiply(factorial[a], inverse_factorial[b]), inverse_factorial[a - b]);
}

std::vector<std::pair<int, int>> prime_factorise(int n) {
    std::vector<std::pair<int, int>> ret;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            int cnt = 0;
            do {
                cnt++;
                n /= i;
            } while (n % i == 0);
            ret.emplace_back(i, cnt);
        }
    }
    if (n > 1) ret.emplace_back(n, 1);
    return ret;
}

int main() {
    precompute_factorials();
    int n;
    long long m;
    std::cin >> n >> m;
    auto prime_factors = prime_factorise(m);
    int answer = 1;
    for (auto [_, cnt] : prime_factors) {
        answer = mod_operations::multiply(answer, binomial_coefficient(n + cnt - 1, cnt));
    }
    std::cout << answer << std::endl;
    return 0;
}