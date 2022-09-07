/* this solution relies on the constraint on D */
#include <bits/stdc++.h>
using namespace std;

void solve() {
	int d, n, k;
	cin >> d >> n >> k;
	vector<int> h(n), s(n), e(n);
	vector<vector<int>> start(d + 2), finish(d + 2);
	for (int i = 0; i < n; ++i) {
		cin >> h[i] >> s[i] >> e[i];
		start[s[i]].push_back(i);
		finish[e[i] + 1].push_back(i);
	}
	set<pair<int, int>> chosen, cands;
	long long ans = 0, cur = 0;
	for (int day = 1; day <= d; ++day) {
		for (int i : finish[day]) {
			if (chosen.count({h[i], i})) {
                chosen.erase({h[i], i});
                cur -= h[i];
                if (!cands.empty()) {
                    int j = cands.rbegin()->second;
                    cands.erase({h[j], j}), chosen.insert({h[j], j});
                    cur += h[j];
                }
            } else {
                cands.erase({h[i], i});
            }
		}
		for (int i : start[day]) {
			if (chosen.size() < k) {
				chosen.insert({h[i], i});
				cur += h[i];
			} else {
				int j = chosen.begin()->second;
				if (h[i] > h[j]) {
					chosen.erase({h[j], j});
					cur -= h[j];
					cands.insert({h[j], j});
					chosen.insert({h[i], i});
					cur += h[i];
				} else {
					cands.insert({h[i], i});
				}
			}
		}
		ans = max(ans, cur);
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; ++test_case) {
		cout << "Case #" << test_case << ": ";
		solve();
	}
	return 0;
}