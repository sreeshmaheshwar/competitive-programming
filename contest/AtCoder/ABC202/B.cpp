#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	for (char c : string(s.rbegin(), s.rend())) {
		cout << (c == '6' ? '9' : (c == '9' ? '6' : c));
	}
	return 0;
}