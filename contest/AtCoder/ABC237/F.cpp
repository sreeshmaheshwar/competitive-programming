#include <algorithm>
#include <iostream>
#include <functional>
#include <map>
#include <vector>

const int MOD = 998244353;
const int LIS_LENGTH = 3;

std::vector<int> replace_subseq(std::vector<int> subseq, const int& element) {
	auto it = std::lower_bound(subseq.begin(), subseq.end(), element);
	if (it == subseq.end()) {
		subseq.push_back(element);
	} else {
		*it = element;
	}
	return subseq;
}

// returns all non-decreasing sequences of size at most `len` with elements between 1 and `m`
std::vector<std::vector<int>> get_subseqs(int len, int m) {
	std::vector<std::vector<int>> ret;
	std::vector<int> seq;
	std::function<void()> dfs = [&]() -> void {
		ret.push_back(seq);
		if ((int) seq.size() < len) {
			for (int i = (seq.empty() ? 1 : seq.back()); i <= m; ++i) {
				seq.push_back(i);
				dfs();
				seq.pop_back();
			}
		}
	};
	dfs();
	return ret;
}

int main() {
	int n, m;
	std::cin >> n >> m;
	
	const auto subseqs = get_subseqs(LIS_LENGTH, m);

	std::map<std::vector<int>, int> dp;
	dp[{}] = 1;
	while (n--) {
		std::map<std::vector<int>, int> new_dp;
		for (auto subseq : subseqs) {
			for (int element = 1; element <= m; ++element) {
				const auto new_subseq = replace_subseq(subseq, element);
				if ((int) new_subseq.size() <= 3)
					new_dp[new_subseq] = (new_dp[new_subseq] + dp[subseq]) % MOD;
			}
		}
		dp.swap(new_dp);
	}

	int ans = 0;
	for (const auto& [subseq, cnt] : dp)
		if ((int) subseq.size() == LIS_LENGTH) 
			ans = (ans + cnt) % MOD;

	std::cout << ans;
	return 0;
}