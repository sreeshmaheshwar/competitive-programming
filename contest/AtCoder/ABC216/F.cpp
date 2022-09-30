#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
const int MOD = 998244353;

int main() {
	int n;
	std::cin >> n;
	std::vector<std::pair<int, int>> arr(n);
	for (auto& p : arr) 
		std::cin >> p.first;
	for (auto& p : arr) 
		std::cin >> p.second;
	std::sort(arr.begin(), arr.end());
	int ans = 0;
	std::vector<int> dp(arr.back().first + 1);
	dp[0] = 1;
	for (auto [a, b] : arr) {
		for (int i = dp.size() - b - 1; i >= 0; --i) {
			dp[i + b] = (dp[i + b] + dp[i]) % MOD;
			if (i + b <= a) ans = (ans + dp[i]) % MOD;
		}
	}
	std::cout << ans;
	return 0;
}