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

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, q; 
	cin >> n >> q;
	fenwick_tree<long long> ft(n);
	for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        ft.set(i, a);
    }
	while (q--) {
		int type;
		cin >> type; 
		if (type == 1) {
			int ind, val;
			cin >> ind >> val;
            ind--;
            ft.set(ind - 1, val);
		} else {
			int l, r; 
			cin >> l >> r; 
			l--, r--;
			cout << ft.qry(l, r) << '\n';
		}
	}
	return 0;
}