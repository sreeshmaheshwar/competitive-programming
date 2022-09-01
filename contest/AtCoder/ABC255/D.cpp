#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    vector<long long> pref(N + 1);
    for (int i = 0; i < N; ++i) {
        pref[i + 1] = pref[i] + A[i];
    }
    while (Q--) {
        int X;
        cin >> X;
        int j = upper_bound(A.begin(), A.end(), X) - A.begin();
        long long ans_above = pref[N] - pref[j] - (long long) (N - j) * X;
        long long ans_below = (long long) j * X - pref[j] + pref[0];
        cout << ans_above + ans_below << '\n';
    }
    return 0;
}