/*
Solution to:
https://codeforces.com/contest/628/problem/D
*/

#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

inline void add(long long &a, long long b) {
	a += b;
	a %= MOD;
}

int n, m, d;

long long num_below(string s, bool inclusive = true) {
	vector<vector<long long>> dp(m, vector<long long>(2));
	dp[0][1] = 1;
	for (int i = 0; i < n; ++i) {
		vector<vector<long long>> ndp(m, vector<long long>(2));
		for (int cur_mod = 0; cur_mod < m; ++cur_mod) {
			for (int next_dig = 0; next_dig < 10; ++next_dig) {
				if (i % 2 == 1) {
					next_dig = d;
				} else if (next_dig == d) {
					continue;
				}
				// start of DP transitions
				int new_mod = (10 * cur_mod + next_dig) % m;
				if (next_dig == s[i] - '0') add(ndp[new_mod][1], dp[cur_mod][1]);
				else if (next_dig < s[i] - '0') add(ndp[new_mod][0], dp[cur_mod][1]);
				add(ndp[new_mod][0], dp[cur_mod][0]);
				// end of DP transitions
				if (i % 2 == 1) break;
			}
		}
		dp = ndp;
	}
	return (dp[0][0] + inclusive ? dp[0][1] : 0) % MOD;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> m >> d;
	string a, b;
	cin >> a >> b;
	n = a.size();
	long long ans = num_below(b) - num_below(a, false);
	if (ans < 0) ans += MOD;
	cout << ans << '\n';

	return 0;
}