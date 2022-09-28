#include <algorithm>
#include <iostream>
#include <vector>

const int MOD = 998244353;

struct seg_tree {
  private:
	int n;
	std::vector<int> tree;

  public:
	seg_tree(int _n) : n(_n), tree(2 * n) {}

	void upd(int i, int val) {
		tree[i += n] = val;
		while (i /= 2) tree[i] = std::max(tree[2 * i], tree[2 * i + 1]);
	}

	int qry(int l, int r) {
		int ret = 0;
		l += n, r += n;
		while (l <= r) {
			if (l % 2 == 1) ret = std::max(ret, tree[l++]);
			if (r % 2 == 0) ret = std::max(ret, tree[r--]);
			l /= 2, r /= 2;
		}
		return ret;
	}
};

struct robot {
	int x, d;

	bool operator<(const robot& other) const {
		return x < other.x;
	}
};

int main() {
	int n;
	std::cin >> n;
	std::vector<robot> robots(n);
	for (auto& [x, d] : robots) 
		std::cin >> x >> d;

	std::sort(robots.begin(), robots.end());
	
	std::vector<int> dp(n + 1, 1);
	std::vector<int> first_after(n);
	seg_tree ST(n);
	for (int i = n - 1; i >= 0; --i) {
		int j = std::lower_bound(robots.begin(), robots.end(), robot{robots[i].x + robots[i].d, 0}) - robots.begin();
		first_after[i] = (j == i + 1 ? j : ST.qry(i + 1, j - 1));
		dp[i] = (dp[i + 1] + dp[first_after[i]]) % MOD;
		ST.upd(i, first_after[i]);
	}
	std::cout << dp[0] << std::endl;
	return 0;
}