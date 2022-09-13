#include <bits/stdc++.h>
using namespace std;

struct Tree {
    int n;
    vector<vector<int>> adj;
    vector<int> parent, depth, subtree_size;
    vector<int> in_order;

    Tree(int _n) : n(_n) {
    	adj.assign(n, {});
        parent.assign(n, -1);
        depth.assign(n, 0);
        subtree_size.assign(n, 0);
    }

    void add_edge(int a, int b) {
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    void dfs(int u = 0) {
    	in_order.push_back(u);
        subtree_size[u] = 1;
        for (int v : adj[u]) {
        	if (v == parent[u]) continue;
        	parent[v] = u;
        	depth[v] = depth[u] + 1;
            dfs(v);
            subtree_size[u] += subtree_size[v];
        }
    }
};

int main() {
    int n;
    cin >> n;
    Tree tree(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        tree.add_edge(u - 1, v - 1);
    }
    tree.dfs();
    vector<long long> answer(n);
    for (int i = 0; i < n; ++i) {
    	answer[0] += tree.depth[i];
    }
    for (int node : tree.in_order) {
    	if (node) answer[node] = answer[tree.parent[node]] + n - 2 * tree.subtree_size[node];
    }
    for (int i = 0; i < n; ++i) {
    	cout << answer[i] << '\n';
    }
    return 0;
}