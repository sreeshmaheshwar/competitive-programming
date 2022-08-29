#include <bits/stdc++.h>
using namespace std;

/* Solution to https://atcoder.jp/contests/abc183/tasks/abc183_f */

const int MAX_N = 2e5;
int c[MAX_N];

struct union_find {
  private:
	vector<int> sizes, link;
 
  public:
  	vector<map<int, int>> class_cnt;

	union_find() {}
 
	union_find(int n) : sizes(n, 1), link(n, 0) { 
		iota(link.begin(), link.end(), 0);
		class_cnt = vector<map<int, int>>(n);
		for (int i = 0; i < n; ++i) 
			class_cnt[i][c[i]]++;
	}
 
	int find(int x) { return x == link[x] ? x : link[x] = find(link[x]); }
 
	void unite(int x, int y) {
		x = find(x); y = find(y);
		if (x == y) return;
		if (sizes[x] < sizes[y])
			swap(x, y);
			
		for (auto entry : class_cnt[y])
			class_cnt[x][entry.first] += entry.second;
		map<int, int>().swap(class_cnt[y]);
		sizes[x] += sizes[y];
		link[y] = x;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, q; 
	cin >> n >> q;
	for (int i = 0; i < n; ++i) {
		cin >> c[i];
		c[i]--;
	}
	union_find uf(n);
	while (q--) {
		int type, a, b;
		cin >> type >> a >> b; 
		a--, b--;
		if (type == 1) {
			uf.unite(a, b);
		} else {
			cout << uf.class_cnt[uf.find(a)][b] << '\n';
		}
	}

	return 0;
}