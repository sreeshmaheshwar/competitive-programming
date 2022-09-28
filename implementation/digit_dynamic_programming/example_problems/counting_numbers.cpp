/*
Solution to: https://cses.fi/problemset/task/2220
*/

#include <bits/stdc++.h>
using namespace std;

long long dp[20][10][2];

long long num_below(string s) {
	memset(dp, 0, sizeof(dp));
	int n = s.size();

	for (int i = 0; i < n; ++i) {
		for (int prv = 0; prv < 10; ++prv) {
			for (int d = 0; d < 10; ++d) {
				if ((!i && !d) || prv == d) continue;
				if (d == s[i] - '0') {
					if (i == 0) dp[i + 1][d][1] = 1;
					else dp[i + 1][d][1] += dp[i][prv][1];
				} else if (d < s[i] - '0') {
					if (i == 0) dp[i + 1][d][0] = 1;
					else dp[i + 1][d][0] += dp[i][prv][1];
				}
				if (i) dp[i + 1][d][0] += dp[i][prv][0];
			}
		}
	}

	long long ans = 0;
	for (int i = 0; i < 10; ++i) 
		for (int j = 0; j < 2; ++j) 
			ans += dp[n][i][j];
	return ans;
}

long long f(long long x) {
	if (x < 0) return 0;
	if (x == 0) return 1;
	string s = to_string(x);
	long long ans = 1; 
	for (int len = 1; len < (int) s.size(); ++len)
		ans += num_below(string(len, '9'));
	return ans + num_below(s);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	long long a, b;
	cin >> a >> b;
	cout << f(b) - f(a - 1) << endl;

	return 0;
}