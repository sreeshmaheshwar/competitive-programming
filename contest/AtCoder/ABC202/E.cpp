#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<vector<int>> children(n);
	for (int i = 1; i < n; ++i) {
		int p;
		cin >> p;
		children[p - 1].push_back(i);
	}
	int node_id = 0;
	vector<int> pre_order(n);
	vector<int> pre_order_start(n), pre_order_end(n), depth(n, 0);
	function<void(int)> dfs = [&](int node) {
		pre_order[node_id] = node;
		pre_order_start[node] = node_id++;
		for (const int &child : children[node]) {
			depth[child] = depth[node] + 1;
			dfs(child);
		}
		pre_order_end[node] = node_id;
	};
	dfs(0);
	vector<vector<int>> at_depth(n);
	for (int i = 0; i < n; ++i) {
		at_depth[depth[pre_order[i]]].push_back(i);
	}
	int q;
	cin >> q;
	while (q--) {
		int node, d;
		cin >> node >> d;
		auto l_it = lower_bound(at_depth[d].begin(), at_depth[d].end(), pre_order_start[node - 1]);
		auto r_it = lower_bound(at_depth[d].begin(), at_depth[d].end(), pre_order_end[node - 1]);
		cout << distance(l_it, r_it) << '\n';
	}
	return 0;
}

// Explanation:
// let pre_order be the in order traversal array of the tree, and let [l, r) be the subarray
// corresponding to the subtree of U, in the current query.
// then, we want to count all nodes i with pre_order[i] in [l, r) and depth[i] = d.
// for each depth d (0 <= d < n), let's store all pre_order indices with nodes of this depth.
// depth[d] stores, e.g. {3, 5, 9} means the nodes at indices 3, 5, 9 in the in order traversal
// have depth d. so, if our query is depth D and we have this [l, r) refering to tour indices, then 
// we we want to count indices in depth[D] with l <= i < r. but, since depth[D] is sorted,
// we can just binary search over depth[D] to find the first position greater or equal to r (say p1) and
// the first position greater than or equal to l (say p2). then all indices of depth[D] in [p1, p2) lie
// in [l, r), of which there are p2 - p1.