#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

vector<long long> dijkstra(const vector<vector<pair<int, int>>>& adj, int start_node) {
    int n = adj.size();
    
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> q;
    vector<long long> dist(n, INF);
    vector<bool> processed(n, false);

    dist[start_node] = 0;
    q.emplace(dist[start_node], start_node);

    while (!q.empty()) {
        int u = q.top().second;
        q.pop();
        if (processed[u]) continue;

        processed[u] = true;
        for (auto [v, weight] : adj[u]) {
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                q.emplace(dist[v], v);
            }
        }
    }
    return dist;
}

/*
Example main program, solution to:
https://cses.fi/problemset/result/4657541/
*/

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n), transpose_adj(n);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        adj[u].emplace_back(v, w);
        transpose_adj[v].emplace_back(u, w);
    }
    auto dist_from = dijkstra(adj, 0);
    auto dist_to = dijkstra(transpose_adj, n - 1);
    long long ans = INF;
    for (int u = 0; u < n; ++u)
        for (auto [v, w] : adj[u])
            ans = min(ans, dist_from[u] + w / 2 + dist_to[v]);
    cout << ans << '\n';
    return 0;
}