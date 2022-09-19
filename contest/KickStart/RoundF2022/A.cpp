#include <bits/stdc++.h>
using namespace std;

struct fabric {
    string c;
    int d, u;
};

void solve() {
    int n;
    cin >> n;
    vector<fabric> ada_fabrics(n), charles_fabrics(n);
    for (int i = 0; i < n; ++i) {
        string c;
        int d, u;
        cin >> c >> d >> u;
        ada_fabrics[i] = charles_fabrics[i] = fabric{c, d, u};
    }

    sort(ada_fabrics.begin(), ada_fabrics.end(), [&](const fabric& a, const fabric& b) {
        if (a.c == b.c) return a.u < b.u;
        return a.c < b.c;
    });
    sort(charles_fabrics.begin(), charles_fabrics.end(), [&](const fabric& a, const fabric& b) {
        if (a.d == b.d) return a.u < b.u;
        return a.d < b.d;
    });

    int answer = 0;
    for (int i = 0; i < n; ++i) {
        answer += ada_fabrics[i].u == charles_fabrics[i].u;
    }
    cout << answer << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int test_case = 1; test_case <= T; ++test_case) {
        cout << "Case #" << test_case << ": ";
        solve();
    }
    
    return 0;
}