#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<vector<int>> positions(n + 1);
	for (int i = 1; i <= n; ++i) {
		int a;
		cin >> a;
		positions[a].push_back(i);
	}
	int answer = n, previous_position = 0;
	for (int i = 1; i <= n; ++i) {
		auto it = upper_bound(positions[i].begin(), positions[i].end(), previous_position);
		if (it == positions[i].end()) break;
		answer = min(answer, n - i);
		previous_position = *it;
	}
	cout << (answer == n ? -1 : answer) << endl;
	return 0;
}