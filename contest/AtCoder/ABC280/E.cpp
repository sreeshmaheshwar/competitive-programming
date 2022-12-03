#include <bits/stdc++.h>
#include <atcoder/modint>

int main() {
    int N, P;
    std::cin >> N >> P;

    using mod_int = atcoder::modint998244353;
    mod_int p = mod_int(P) / 100;

    vector<mod_int> dp(N + 1);
    for (int i = 1; i <= N; ++i) 
        dp[i] = p * ((i == 1 ? 0 : dp[i - 2]) + 1) + (1 - p) * (dp[i - 1] + 1);

    cout << dp[N].val();
}