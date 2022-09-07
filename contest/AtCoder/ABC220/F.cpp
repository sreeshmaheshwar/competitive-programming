#include <bits/stdc++.h>
using namespace std;

/* Start of pre-written (library) code, from https://github.com/nealwu/competitive-programming, fully credited to Neal Wu */
int highest_bit(int x) {
    return x == 0 ? -1 : 31 - __builtin_clz(x);
}
struct segment_change {
    long long to_sum;
    segment_change(long long _to_sum = 0) : to_sum(_to_sum) {}
    void reset() {
        to_sum = 0;
    }
    bool has_change() const {
        return to_sum != 0;
    }
    segment_change combine(const segment_change &other) const {
        return segment_change(to_sum + other.to_sum);
    }
};
struct segment {
    long long sum;
    segment(long long _sum = 0) : sum(_sum) {}
    bool empty() const {
        return sum == 0;
    }
    void apply(int, const segment_change &change) {
        sum = sum + change.to_sum;
    }
    void join(const segment &other) {
        sum = sum + other.sum;
    }
    void join(const segment &a, const segment &b) {
        *this = a;
        join(b);
    }
};
pair<int, int> right_half[32];
struct seg_tree {
    int tree_n = 0;
    vector<segment> tree;
    vector<segment_change> changes;
    seg_tree(int n = -1) {
        if (n >= 0) init(n);
    }
    void init(int n) {
        tree_n = 1;
        while (tree_n < n) tree_n *= 2;
        tree.assign(2 * tree_n, segment());
        changes.assign(tree_n, segment_change());
    }
    void build(const vector<segment> &initial) {
        int n = int(initial.size());
        init(n);
        assert(n <= tree_n);
        for (int i = 0; i < n; i++) tree[tree_n + i] = initial[i];
        for (int position = tree_n - 1; position > 0; position--) tree[position].join(tree[2 * position], tree[2 * position + 1]);
    }
    void apply_and_combine(int position, int length, const segment_change &change) {
        tree[position].apply(length, change);
        if (position < tree_n) changes[position] = changes[position].combine(change);
    }
    void push_down(int position, int length) {
        if (changes[position].has_change()) {
            apply_and_combine(2 * position, length / 2, changes[position]);
            apply_and_combine(2 * position + 1, length / 2, changes[position]);
            changes[position].reset();
        }
    }
    void push_all(int a, int b) {
        assert(0 <= a && a < b && b <= tree_n);
        a += tree_n;
        b += tree_n - 1;
        for (int up = highest_bit(tree_n); up > 0; up--) {
            int x = a >> up, y = b >> up;
            push_down(x, 1 << up);
            if (x != y) push_down(y, 1 << up);
        }
    }
    void join_and_apply(int position, int length) {
        tree[position].join(tree[2 * position], tree[2 * position + 1]);
        tree[position].apply(length, changes[position]);
    }
    void join_all(int a, int b) {
        assert(0 <= a && a < b && b <= tree_n);
        a += tree_n;
        b += tree_n - 1;
        int length = 1;
        while (a > 1) {
            a /= 2;
            b /= 2;
            length *= 2;
            join_and_apply(a, length);
            if (a != b) join_and_apply(b, length);
        }
    }
    template<typename T_range_op>
    void process_range(int a, int b, bool needs_join, T_range_op &&range_op) {
        if (a == b) return;
        push_all(a, b);
        int original_a = a, original_b = b;
        int length = 1, r_size = 0;
        for (a += tree_n, b += tree_n; a < b; a /= 2, b /= 2, length *= 2) {
            if (a & 1) range_op(a++, length);
            if (b & 1) right_half[r_size++] = {--b, length};
        }
        for (int i = r_size - 1; i >= 0; i--) range_op(right_half[i].first, right_half[i].second);
        if (needs_join) join_all(original_a, original_b);
    }
    segment query(int a, int b) {
        assert(0 <= a && a <= b && b <= tree_n);
        segment answer;
        process_range(a, b, false, [&](int position, int) {
            answer.join(tree[position]);
        });
        return answer;
    }
    void update(int a, int b, const segment_change &change) {
        assert(0 <= a && a <= b && b <= tree_n);
        process_range(a, b, true, [&](int position, int length) {apply_and_combine(position, length, change);});
    }
};
struct Tree {
    int n = 0;
    vector<vector<int>> adj;
    vector<int> parent, depth, subtree_size;
    vector<int> tour_start, tour_end;
    vector<int> tour_list;
    Tree(int _n = 0) {
        init(_n);
    }
    void init(int _n) {
        n = _n;
        adj.assign(n, {});
        parent.resize(n);
        depth.resize(n);
        subtree_size.resize(n);
        tour_start.resize(n);
        tour_end.resize(n);
        tour_list.resize(n);
    }
    void add_edge(int a, int b) {
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    void dfs(int node, int par) {
        parent[node] = par;
        depth[node] = par < 0 ? 0 : depth[par] + 1;
        subtree_size[node] = 1;
        adj[node].erase(remove(adj[node].begin(), adj[node].end(), par), adj[node].end());
        for (int child : adj[node]) {
            dfs(child, node);
            subtree_size[node] += subtree_size[child];
        }
    }
    int tour;
    void tour_dfs(int node) {
        tour_list[tour] = node;
        tour_start[node] = tour++;
        for (int child : adj[node]) {
            tour_dfs(child);
        }
        tour_end[node] = tour;
    }
    void build(int root = 0) {
        parent.assign(n, -1);
        dfs(root, -1);
        tour = 0;
        tour_dfs(root);
    }
};
/* End of pre-written (library) code, from https://github.com/nealwu/competitive-programming, fully credited to Neal Wu */

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    Tree tree(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        tree.add_edge(u, v);
    }
    tree.build();
    vector<long long> pref_ordered_depths(n + 1);
    pref_ordered_depths[0] = 0;
    for (int i = 0; i < n; ++i) {
        pref_ordered_depths[i + 1] = pref_ordered_depths[i] + tree.depth[tree.tour_list[i]];
    }
    auto get_sum_of_depths = [&](int root) -> long long {
        return pref_ordered_depths[tree.tour_end[root]] - pref_ordered_depths[tree.tour_start[root]];
    };
    seg_tree delta(n), count(n);
    for (int u = 0; u < n; ++u) { // iterate over LCA - update all nodes with paths corresponding to `u` as its LCA
        for (int v : tree.adj[u]) {
            long long cnt = tree.subtree_size[u] - tree.subtree_size[v];
            delta.update(tree.tour_start[v], tree.tour_end[v], get_sum_of_depths(u) - get_sum_of_depths(v) - 2 * cnt * tree.depth[u]);
            count.update(tree.tour_start[v], tree.tour_end[v], cnt);
        }
        delta.update(tree.tour_start[u], tree.tour_start[u] + 1, get_sum_of_depths(u) - (long long) tree.subtree_size[u] * tree.depth[u]);
    }
    for (int i = 0; i < n; ++i) {
        cout << count.query(tree.tour_start[i], tree.tour_start[i] + 1).sum * tree.depth[i] + delta.query(tree.tour_start[i], tree.tour_start[i] + 1).sum << '\n';
    }
    return 0;
}