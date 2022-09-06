/* 
Description: 
    Order statistic segment tree for bounded values with considerably less memory usage than __gnu_pbds implementation.
    Supports multiset insertion, deletion and kth order statistic query all in (I believe) O(log N).
    kth order statistic query is implemented using O(log N) binary search on segment tree.
    See https://github.com/atcoder/ac-library for the AtCoder segment tree implementation used here.
Solution to:
    https://codeforces.com/contest/1354/problem/D 
*/

#include <bits/stdc++.h>
#include <atcoder/segtree>
using namespace std;

int _op(int x, int y) {
    return x + y;
}

int _unit() {
    return 0;
}

using segtree = atcoder::segtree<int, _op, _unit>;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;

    segtree st(n + 1);
    auto change_val = [&](int val, int delta) -> void {
        st.set(val, st.get(val) + delta);
    };
    auto get_kth_statistic = [&](int k) -> int {
        int ret = st.max_right(0, [&k](int num_below) {
            return num_below < k;
        });
        return (ret == n + 1 ? 0 : ret);
    };

    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        change_val(a, +1);
    }
    while (q--) {
        int k;
        cin >> k;
        if (k < 0) {
            change_val(get_kth_statistic(-k), -1);
        } else {
            change_val(k, +1);
        }
    }
    cout << get_kth_statistic(1) << '\n';
    return 0;
}