#include <bits/stdc++.h>

/* Description: Disjoint Set Union data structure, with
   path compression and union by size optimisations, to
   allow for near constant time (amortized) queries. */
struct union_find {
  private:
    int num_components;
    std::vector<int> sizes, link;

  public:
    union_find(int _num_components) : num_components(_num_components) {
        sizes.assign(num_components, 1);
        link.resize(num_components);
        std::iota(link.begin(), link.end(), 0);
    }

    int count() const { return num_components; }
    int size(int x) { return sizes[find(x)]; }
    int find(int x) { return x == link[x] ? x : link[x] = find(link[x]); }

    bool unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return false;
        /* Ensure that y is a smaller set than x. */
        if (sizes[x] < sizes[y]) std::swap(x, y);
        /* Merge y into x. */
        sizes[x] += sizes[y];
        link[y] = x;
        num_components--;
        return true;
    }
};

int main() {
    int n, m, queries;
    std::cin >> n >> m >> queries;

    union_find dsu(n);
    std::vector<std::vector<std::pair<int, int>>> adj(n);
    for (int i = 0, u, v, w; i < m; ++i) {
        std::cin >> u >> v >> w, u--, v--;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, -w);
        dsu.unite(u, v);
    }

    std::vector<long long> dist(n, -1);
    std::vector<bool> has_bad_cycle(n, false);
    for (int i = 0; i < n; ++i) {
        if (dsu.find(i) != i) continue;
        std::queue<int> q;
        dist[i] = 0;
        q.emplace(i);
        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (auto [v, w] : adj[u]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + w;
                    q.emplace(v);
                } else if (dist[v] != dist[u] + w) {
                    has_bad_cycle[i] = true;
                }
            }
        }
    }

    for (int i = 0, u, v; i < queries; ++i) {
        std::cin >> u >> v, u--, v--;
        if (dsu.find(u) != dsu.find(v)) {
            std::cout << "nan" << '\n';
        } else if (has_bad_cycle[dsu.find(u)]) {
            std::cout << "inf" << '\n';
        } else {
            std::cout << dist[v] - dist[u] << '\n';
        }
    }
}