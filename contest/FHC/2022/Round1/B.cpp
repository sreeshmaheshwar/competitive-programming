#include <bits/stdc++.h>
using namespace std;
constexpr int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    long long sum_a = 0, sum_b = 0, sum_a_sq = 0, sum_b_sq = 0;
    for (int i = 0; i < n; ++i) {
    	long long a, b;
    	cin >> a >> b;
    	sum_a = (sum_a + a) % MOD;
    	sum_b = (sum_b + b) % MOD;
    	sum_a_sq = (sum_a_sq + a * a) % MOD;
    	sum_b_sq = (sum_b_sq + b * b) % MOD;
    }
    int q;
    cin >> q;
    long long answer = 0;
    while (q--) {
    	long long x, y;
    	cin >> x >> y;
    	answer = (answer + ((x * x) % MOD) * n) % MOD;
    	answer = (answer + ((y * y) % MOD) * n) % MOD;
    	answer = (answer - ((x * sum_a) % MOD) * 2 + 2 * MOD) % MOD;
    	answer = (answer - ((y * sum_b) % MOD) * 2 + 2 * MOD) % MOD;
    	answer = (answer + sum_a_sq + sum_b_sq) % MOD;
    }
    cout << answer << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int test_case = 1; test_case <= T; ++test_case) {
        cout << "Case #" << test_case << ": ";
        solve();
    }
    
    return 0;
}