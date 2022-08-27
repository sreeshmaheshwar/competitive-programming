/*
Solution to:
https://atcoder.jp/contests/abc253/tasks/abc253_e
*/

#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using mint = atcoder::modint998244353;

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
        if (l > r) return T(0);
        return sum(r) - sum(l - 1); 
    }
 
    void upd_by(int index, T delta) { 
        for (; index < n; index = index | (index + 1))
            data[index] += delta;
    }
};

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    fenwick_tree<mint> ft(m);
    for (int i = 0; i < m; ++i)
        ft.upd_by(i, 1);
    for (int i = 0; i < n - 1; ++i) {
        fenwick_tree<mint> new_ft(m);
        for (int j = 0; j < m; ++j) 
            new_ft.upd_by(j, ft.qry(0, m - 1) - ft.qry(max(0, j - k + 1), min(m - 1, j + k - 1)));
        ft = new_ft;
    }
    cout << ft.qry(0, m - 1).val() << '\n';
    return 0;
}