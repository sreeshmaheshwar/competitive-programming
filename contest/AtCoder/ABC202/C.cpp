#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> count(n);
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		a--;
		count[a]++;
	}
	vector<int> b(n);
	for (int i = 0; i < n; ++i) {
		cin >> b[i];
		b[i]--;
	}
	long long answer = 0;
	for (int i = 0; i < n; ++i) {
		int c;
		cin >> c;
		c--;
		answer += count[b[c]];
	}
	cout << answer << endl;
	return 0;
}