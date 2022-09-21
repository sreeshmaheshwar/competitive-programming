#include <bits/stdc++.h>
using namespace std;

int main() {
    int test_cases;
    cin >> test_cases;
    while (test_cases--) {
        int n, x, y;
        cin >> n >> x >> y;
        string a, b;
        cin >> a >> b;
        vector<int> diffs;
        for (int i = 0; i < n; ++i)
            if (a[i] != b[i])
                diffs.push_back(i);
        int num_diffs = diffs.size();
        if (num_diffs % 2) {
            cout << -1 << '\n';
        } else {
            if (num_diffs == 2 && diffs[1] == diffs[0] + 1) {
                cout << min(x, 2 * y) << '\n';
            } else {
                cout << (long long) y * (num_diffs / 2) << '\n';
            }
        }
    }
    return 0;
}