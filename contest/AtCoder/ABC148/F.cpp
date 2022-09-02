#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, u, v;
	cin >> n >> u >> v;
	u--, v--;
	vector<vector<int>> adj(n);
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	vector<int> depth(n, 0), max_leaf_depth(n, 0), parent(n, -1);
	function<void(int)> dfs = [&](int node) {
		for (int child : adj[node]) {
			if (child == parent[node]) continue;
			parent[child] = node;
			depth[child] = depth[node] + 1;
			dfs(child);
			max_leaf_depth[node] = max(max_leaf_depth[node], max_leaf_depth[child] + 1);
		}
	};
	dfs(v);
	int subtree_root = u, dist_from_u = 0, answer = 0;
	while (dist_from_u < depth[subtree_root]) {
		answer = max(answer, depth[subtree_root] + max_leaf_depth[subtree_root] - 1);
		subtree_root = parent[subtree_root];
		dist_from_u++;
	}
	cout << answer << endl;
	return 0;
}