#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using mint = atcoder::modint998244353;

inline int floor_div(int a, int b) {
    return a / b - ((a ^ b) < 0 && a % b != 0);
}

int main() {
    int N, D;
    cin >> N >> D;

    vector<mint> pref(D + 2);
    for (int i = 0; i <= D; ++i)
        pref[i + 1] = pref[i] + (i == 0 ? mint(2).pow(D) : (i == D ? 1 : mint(2).pow(D - i - 1)));

    auto qry = [&](int L, int R) -> mint {
        return L > R ? 0 : pref[min(R, D) + 1] - pref[max(0, L)];
    };

    mint ans = 0;
    for (int d = 0; d < N; ++d)
        ans += mint(2).pow(d) * qry(1 + floor_div(D + d - N, 2), d);
    cout << ans.val() << endl;
    return 0;
}