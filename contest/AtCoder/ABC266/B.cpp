#include <bits/stdc++.h>
const int MOD = 998244353;

int main() {
    long long N;
    std::cin >> N;
    long long X = std::abs(N) % MOD;
    if (N < 0) X = (MOD - X) % MOD;
    std::cout << X << std::endl;
    return 0;
}