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

// computes number of inversions in a given array in O(N log N) time
long long count_inversions(vector<int>& a) {
	int n = (int) a.size();

	// coordinate compression: (so all elements are < n)
	vector<pair<int, int>> b(n);
	for (int i = 0; i < n; ++i) b[i] = {a[i], i};
	sort(b.begin(), b.end());

	int id = 0;
	for (int i = 0; i < n; ++i) {
		if (i && b[i].first != b[i - 1].first) id++;
		a[b[i].second] = id;
	}

	// inversion counting (from right to left):
	fenwick_tree<int> ft(n);
	long long ans = 0;
	for (int i = n - 1; i >= 0; --i) {
		ans += ft.sum(a[i] - 1);
		ft.upd_by(a[i], 1);
	}
	return ans;
}

/*
Example Main Program:
(solution to https://atcoder.jp/contests/abc261/tasks/abc261_f)
*/

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; 
	cin >> n;
	vector<int> a(n), c(n);
	vector<vector<int>> x(n);
	for (int i = 0; i < n; ++i) {
		cin >> c[i];
		c[i]--;
	}
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		a[i]--;
		x[c[i]].push_back(a[i]);
	}

	long long ans = count_inversions(a);
	for (int i = 0; i < n; ++i) {
		ans -= count_inversions(x[i]);
	}
	cout << ans << '\n';

	return 0;
}