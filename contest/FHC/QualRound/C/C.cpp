#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string c;
    cin >> c;
    for (int i = 0; i < n - 1; ++i) {
        cout << (c[0] == '-' ? '.' : '-');
        for (int j = 0; j < 9; ++j) {
            cout << (i >> j & 1 ? '-' : '.');
        }
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for (int test_case = 1; test_case <= T; ++test_case) {
        cout << "Case #" << test_case << ":\n";
        solve();
    }
    return 0;
}