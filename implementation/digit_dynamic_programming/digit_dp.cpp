/*
Solution to:
https://codingcompetitions.withgoogle.com/kickstart/round/0000000000050ff4/0000000000051183#problem
*/

#include <bits/stdc++.h>
using namespace std;

// remember to use 64-bit integers where necessary (!!!)
long long dp[20][9][2];
// DP state is (length of prefix, sum mod 9, tight)

long long num_below(string s) {
	int n = (int) s.size();
	memset(dp, 0, sizeof(dp));
	dp[0][0][1] = 1;
	for (int i = 0; i < n; ++i) {
		int cur = s[i] - '0';
		for (int sum = 0; sum < 9; ++sum) {
			for (int d = 0; d < 9; ++d) { // should be d < 10 in general case (!!!)
				if (d == cur) { // tight -> tight
					dp[i + 1][(sum + d) % 9][1] += dp[i][sum][1];
				} else if (d < cur) { // tight -> not tight
					dp[i + 1][(sum + d) % 9][0] += dp[i][sum][1];
				}
				dp[i + 1][(sum + d) % 9][0] += dp[i][sum][0]; // not tight -> tight
			}
		}
	}
	long long ans = 0;
	for (int sum = 1; sum < 9; ++ sum) ans += dp[n][sum][0] + dp[n][sum][1];
	return ans;
}

void solve() {
	long long l, r;
	cin >> l >> r; 
	cout << num_below(to_string(r)) - num_below(to_string(l - 1)) << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T; cin >> T;
	for (int test_case = 1; test_case <= T; ++test_case) {
		cout << "Case #" << test_case << ": ";
		solve();
	}
	
	return 0;
}