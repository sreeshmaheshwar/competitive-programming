#include <bits/stdc++.h>
using namespace std;
 
struct fenwick_tree {
 
    vector<long long> bit;
    int n;
 
    fenwick_tree(int _n) : n(_n) {
        bit.assign(n, 0);
    }
 
    fenwick_tree(vector<int> a) : fenwick_tree((int) a.size()) {
        for (int i = 0; i < (int) a.size(); ++i) {
        	upd_by(i, a[i]);
        }
    }
 
    long long sum(int r) {
        long long res = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            res += bit[r];
        return res;
    }
 
    long long qry(int l, int r) { 
        return sum(r) - sum(l - 1); 
    }
 
    void upd_by(int idx, long long delta) { 
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};
 
/*
Standard Fenwick Tree
Usage:
    fenwick_tree ft(n);
Notes: 
    update method uses DELTA not VALUE
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
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	fenwick_tree ft(arr);
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