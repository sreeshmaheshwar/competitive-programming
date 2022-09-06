/* 
Description: 
    Order statistic Fenwick tree for bounded values with considerably less memory usage than __gnu_pbds implementation.
    Supports multiset insertion, deletion in O(log N).
    Supports kth order statistic query in O(log^2 N), using naive binary search on prefix sums.
Solution to:
    https://codeforces.com/contest/1354/problem/D 
Note:
    For kth order statistic Fenwick Tree query in O(log N), see https://codeforces.com/blog/entry/61364
*/

#include <bits/stdc++.h>
using namespace std;

template<typename T> struct fenwick_tree {
    vector<T> data;
    int n;

    fenwick_tree(int _n) : n(_n) {
        data.assign(n, T(0));
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
        for (; index < n; index = index | (index + 1))
            data[index] += delta;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    fenwick_tree<int> ft(n + 1);
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        ft.upd_by(a, +1);
    }

    auto get_kth_statistic = [&](int k) -> int {
        int lo = 1, hi = n, ret = 0;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            int num_below = ft.sum(mid);
            if (num_below >= k) {
                ret = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return ret;
    };

    for (int i = 0; i < q; ++i) {
        int k;
        cin >> k;
        if (k < 0) {
            k *= -1;
            ft.upd_by(get_kth_statistic(k), -1);
        } else {
            ft.upd_by(k, +1);
        }
    }
    cout << get_kth_statistic(1) << '\n';
    return 0;
}