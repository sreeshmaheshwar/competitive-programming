#include <bits/stdc++.h>
using namespace std;

int main() {
    int test_cases;
    cin >> test_cases;
    while (test_cases--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int& x : a) cin >> x;
        if (n == 1) {
            cout << 0 << '\n';
        } else {
            vector<pair<int, int>> operations;
            operations.emplace_back(0, n - 1);
            a[0] = (a[0] + a[n - 1]) % 2 ? a[0] : a[n - 1];
            for (int i = 1; i < n - 1; ++i) {
                if (a[i] % 2 == a[0] % 2) {
                    operations.emplace_back(i, n - 1);
                } else {
                    operations.emplace_back(0, i);
                }
            }
            cout << operations.size() << '\n';
            for (const auto& [l, r] : operations)
                cout << l + 1 << " " << r + 1 << '\n';
        }
    }
    return 0;
}