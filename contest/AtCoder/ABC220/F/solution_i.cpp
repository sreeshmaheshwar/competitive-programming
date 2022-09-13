#include <bits/stdc++.h>
using namespace std;

struct Tree {
    int n, timer;
    vector<vector<int>> adj;
    vector<int> parent, depth, subtree_size;
    vector<int> time_in, time_out;
    vector<int> pre_order;

    Tree(int _n) : n(_n) {
    	adj.assign(n, {});
        parent.assign(n, -1);
        depth.assign(n, 0);
        subtree_size.assign(n, 0);
        time_in.resize(n);
        time_out.resize(n);
    }

    void add_edge(int a, int b) {
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    void dfs(int u) {
    	pre_order.push_back(u);
    	time_in[u] = timer++;
        subtree_size[u] = 1;
        for (int v : adj[u]) {
        	if (v == parent[u]) continue;
        	parent[v] = u;
        	depth[v] = depth[u] + 1;
            dfs(v);
            subtree_size[u] += subtree_size[v];
        }
        time_out[u] = timer;
    }

    void build(int root = 0) {
    	timer = 0;
        dfs(root);
    }
};

void update(int l, int r, long long value, vector<long long>& arr) {
	arr[l] += value;
	arr[r] -= value;
}

int main() {
    int n;
    cin >> n;
    Tree tree(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        tree.add_edge(u - 1, v - 1);
    }
    tree.build();

    vector<long long> pref_ordered_depths(n + 1);
    pref_ordered_depths[0] = 0;
    for (int i = 0; i < n; ++i) {
        pref_ordered_depths[i + 1] = pref_ordered_depths[i] + tree.depth[tree.pre_order[i]];
    }
    auto get_sum_of_depths = [&](int root) -> long long {
        return pref_ordered_depths[tree.time_out[root]] - pref_ordered_depths[tree.time_in[root]];
    };

    vector<long long> delta(n + 1), count(n + 1);
    for (int u = 0; u < n; ++u) { // iterate over LCA - update all nodes with paths corresponding to `u` as its LCA
        for (int v : tree.adj[u]) {
        	if (v == tree.parent[u]) continue;
            long long cnt = tree.subtree_size[u] - tree.subtree_size[v];
            update(tree.time_in[v], tree.time_out[v], get_sum_of_depths(u) - get_sum_of_depths(v) - 2 * cnt * tree.depth[u], delta);
            update(tree.time_in[v], tree.time_out[v], cnt, count);
        }
        update(tree.time_in[u], tree.time_in[u] + 1, get_sum_of_depths(u) - (long long) tree.subtree_size[u] * tree.depth[u], delta);
    }
    for (int i = 0; i < n - 1; ++i) {
    	delta[i + 1] += delta[i];
    	count[i + 1] += count[i];
    }
    for (int i = 0; i < n; ++i) {
        cout << count[tree.time_in[i]] * tree.depth[i] + delta[tree.time_in[i]] << '\n';
    }
    return 0;
}