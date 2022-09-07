/* 
Solution to:
https://atcoder.jp/contests/abc256/submissions/34679676 
*/

#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using mint = atcoder::modint998244353;

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

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<fenwick_tree<mint>> ft(3, fenwick_tree<mint>(n));
    
    auto set = [&](int index, int value) -> void {
        for (int i = 0; i < 3; ++i) ft[i].set(index, mint(index).pow(i) * value);
    };
    auto get = [&](int k) -> mint {
        return (ft[0].sum(k)*((mint)k*k+3*k+2)-ft[1].sum(k)*((mint)2*k+3)+ft[2].sum(k))/2;
    };

    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        set(i, a);
    }
    while (q--) {
        int type;
        cin >> type;
        if (type == 2) {
            int x;
            cin >> x;
            x--;
            cout << get(x).val() << '\n';
        } else {
            int x, v;
            cin >> x >> v;
            x--;
            set(x, v);
        }
    }
    return 0;
}