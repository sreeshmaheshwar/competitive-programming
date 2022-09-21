#include <bits/stdc++.h>
using namespace std;

int main() {
    int test_cases;
    cin >> test_cases;
    while (test_cases--) {
        int n, x, y;
        cin >> n >> x >> y;
        if (y < x) swap(x, y);
        if (x || !y || (n - 1) % y) {
            cout << -1;
        } else {
            for (int i = 2; i <= n; i += y)
                for (int rep = 0; rep < y; ++rep)
                    cout << i << " ";
        }
        cout << '\n';
    }
    return 0;
}