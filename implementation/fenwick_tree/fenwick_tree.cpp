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
        // if (l > r) return T(0); // UNCOMMENT IF NEEDED!
        return sum(r) - sum(l - 1); 
    }
 
    void upd_by(int index, T delta) { 
        for (; index < n; index = index | (index + 1))
            data[index] += delta;
    }
};
 
/*
Standard Fenwick Tree
Usage:
    fenwick_tree<T> ft(n);
Notes: 
    update method uses delta NOT updated value
*/


/*
Example Main Program:
(solution to https://cses.fi/problemset/submit/1648/)
*/
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
 
	int n, q; 
	cin >> n >> q;
	vector<int> arr(n);
	fenwick_tree<long long> ft(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		ft.upd_by(i, arr[i]);
	}
	while (q--) {
		int type;
		cin >> type; 
		if (type == 1) {
			int ind, val;
			cin >> ind >> val;
			ind--;
			ft.upd_by(ind, val - arr[ind]);
			arr[ind] = val;
		} else {
			int l, r; 
			cin >> l >> r; 
			l--, r--;
			cout << ft.qry(l, r) << '\n';
		}
	}
	
	return 0;
}