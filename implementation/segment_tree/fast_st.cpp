#include <bits/stdc++.h>
using namespace std;

const int INF = int(1e9) + 5;

struct seg_tree {
  private:
	int n;
	vector<int> tree;

  public:
	seg_tree(int _n) : n(_n), tree(2 * n, INF) {}

	void upd(int i, int val) {
		tree[i += n] = val;
		while (i /= 2) tree[i] = min(tree[2 * i], tree[2 * i + 1]);
	}

	int qry(int l, int r) {
		int ret = INF;
		l += n, r += n;
		while (l <= r) {
			if (l % 2 == 1) ret = min(ret, tree[l++]);
			if (r % 2 == 0) ret = min(ret, tree[r--]);
			l /= 2, r /= 2;
		}
		return ret;
	}
};

/*
Example Main Program,
solution to: https://cses.fi/problemset/task/1649 
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	int n, q;
	cin >> n >> q;
	seg_tree ST(n);
	for (int i = 0, x; i < n; ++i) {
		cin >> x;
		ST.upd(i, x);
	}
	while (q--) {
		int query_type, a, b;
		cin >> query_type >> a >> b;
		if (query_type == 1) {
			ST.upd(a - 1, b);
		} else {
			cout << ST.qry(a - 1, b - 1) << '\n';
		}
	}

    return 0;
}
