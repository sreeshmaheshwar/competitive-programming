#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> trash_location;
	for (int i = 0; i < n; ++i) {
		char c;
		cin >> c; 
		if (c == '1') {
			trash_location.push_back(i);
		}
	}
	long long distance_sum = 0;
	for (int i = 0; i < n; ++i) {
		vector<int>::iterator it = lower_bound(trash_location.begin(), trash_location.end(), i);
		int min_distance_left = it == trash_location.begin() ? INT_MAX : i - *prev(it);
		int min_distance_right = it == trash_location.end() ? INT_MAX : *it - i;
		distance_sum += min(min_distance_left, min_distance_right);
	}
	cout << distance_sum << '\n';
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