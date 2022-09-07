#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using mint = atcoder::modint998244353;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int &a : A) cin >> a;
    vector<mint> dp(10);
    dp[A[0]] = 1;
    for (int i = 0; i < N - 1; ++i) {
        vector<mint> new_dp(10);
        for (int j = 0; j < 10; ++j) {
            new_dp[(j + A[i + 1]) % 10] += dp[j];
            new_dp[(j * A[i + 1]) % 10] += dp[j];
        }
        dp.swap(new_dp);
    }
    for (int i = 0; i < 10; ++i) cout << dp[i].val() << endl;
    return 0;
}