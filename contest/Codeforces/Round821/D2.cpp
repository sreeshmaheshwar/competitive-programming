#include <bits/stdc++.h>
using namespace std;

int main() {
    int test_cases;
    cin >> test_cases;
    while (test_cases--) {
        int n;
        cin >> n;
        long long x, y;
        cin >> x >> y;
        string a, b;
        cin >> a >> b;
        vector<int> diffs;
        for (int i = 0; i < n; ++i)
            if (a[i] != b[i])
                diffs.push_back(i);
        int num_diffs = diffs.size();
        if (num_diffs % 2) {
            cout << -1 << '\n';
        } else if (x >= y) {
            if (num_diffs == 2 && diffs[1] == diffs[0] + 1) 
                cout << min(x, 2 * y) << '\n';
            else 
                cout << y * (num_diffs / 2) << '\n';
        } else {
            vector<long long> dp(num_diffs + 1);
            for (int i = 2; i <= num_diffs; ++i)
                dp[i] = min(dp[i - 2] + min(y, x * (diffs[i - 1] - diffs[i - 2])), dp[i - 1] + (i % 2 ? 0 : y));
            cout << dp.back() << '\n';
        }
    }
    return 0;
}