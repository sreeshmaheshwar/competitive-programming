#include <bits/stdc++.h>
using namespace std;
const int S = 100;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> cnt(S + 1);
    bool impossible = false;
    for (int i = 0; i < n; ++i) {
        int s;
        cin >> s;
        cnt[s]++;
        if (cnt[s] > 2) {
            impossible = true;
        }
    }
    cout << (!impossible && k * 2 >= n ? "YES" : "NO") << '\n';
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