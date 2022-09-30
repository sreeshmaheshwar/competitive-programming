#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

int main() {
	int n, m;
	std::cin >> n >> m;
	std::vector<std::vector<int>> a(m);
	std::vector<std::vector<int>> cylinders(n);
	for (int i = 0, k; i < m; ++i) {
		std::cin >> k;
		a[i].resize(k);
		for (int j = k - 1; j >= 0; --j)
			std::cin >> a[i][j], a[i][j]--;
		cylinders[a[i].back()].push_back(i);
	}
	int removed_colours = 0;
	std::function<void(int)> dfs = [&](int colour) {
		removed_colours++;
		for (int iter = 0; iter < 2; ++iter) {
			int i = cylinders[colour].back();
			cylinders[colour].pop_back();
			a[i].pop_back();
			if (!a[i].empty()) {
				cylinders[a[i].back()].push_back(i);
				if ((int) cylinders[a[i].back()].size() == 2)
					dfs(a[i].back());
			}
		}
	};
	for (int colour = 0; colour < n; ++colour)
		if ((int) cylinders[colour].size() == 2)
			dfs(colour);
	std::cout << (removed_colours == n ? "Yes" : "No");
	return 0;
}