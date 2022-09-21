#include <bits/stdc++.h>
using namespace std;

int main() {
    int test_cases;
    cin >> test_cases;
    while (test_cases--) {
        int n, k;
        cin >> n >> k;
        vector<int> mod_max(k);
        for (int i = 0; i < n; ++i) {
            int a;
            cin >> a;
            mod_max[i % k] = max(mod_max[i % k], a);
        }
        cout << accumulate(mod_max.begin(), mod_max.end(), (long long) 0) << '\n';
    }
    return 0;
}