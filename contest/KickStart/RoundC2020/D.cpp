#include <bits/stdc++.h>
using namespace std;

template<typename T> struct fenwick_tree {
    vector<T> arr, data;
    int n;

    fenwick_tree(int _n) : n(_n) {
        arr = data = vector<T>(n, T(0));
    }
 
    T sum(int r) {
        T res = T(0);
        for (; r >= 0; r = (r & (r + 1)) - 1)
            res += data[r];
        return res;
    }
 
    T qry(int l, int r) { 
        return sum(r) - sum(l - 1); 
    }
 
    void upd_by(int index, T delta) { 
        arr[index] += delta;
        for (; index < n; index = index | (index + 1))
            data[index] += delta;
    }

    void set(int index, T new_val) {
        upd_by(index, new_val - arr[index]);
    }
};

inline int get_sign(int index) {
    return index & 1 ? -1 : +1;
}

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    fenwick_tree<long long> alternating_sum(n + 1), coefficient_sum(n + 1);
    for (int i = 1; i <= n; ++i) {
        alternating_sum.set(i, get_sign(i) * a[i]);
        coefficient_sum.set(i, get_sign(i) * i * a[i]);
    }
    long long ans = 0;
    while (q--) {
        char type;
        cin >> type;
        if (type == 'Q') {
            int l, r;
            cin >> l >> r;
            ans += get_sign(l) * coefficient_sum.qry(l, r) - (l - 1) * get_sign(l) * alternating_sum.qry(l, r);
        } else {
            int i, x;
            cin >> i >> x;
            alternating_sum.set(i, get_sign(i) * x);
            coefficient_sum.set(i, get_sign(i) * i * x);
        }
    }
    cout << ans << '\n';
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