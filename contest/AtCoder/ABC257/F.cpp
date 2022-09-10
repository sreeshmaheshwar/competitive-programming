#include <bits/stdc++.h>
using namespace std;
const int INF = 1e6;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    vector<int> undetermined;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        if (u == -1) {
            undetermined.push_back(v);
        } else {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }
    auto BFS = [&](int start) {
        vector<int> dist(n, INF);
        queue<int> q;
        dist[start] = 0;
        q.push(start);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : adj[u]) {
                if (dist[v] == INF) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
        return dist;
    };
    auto dist_from_start = BFS(0);
    auto dist_to_end = BFS(n - 1);
    int min_to = INF, min_from = INF;
    for (int u : undetermined) {
        min_to = min(min_to, dist_to_end[u]);
        min_from = min(min_from, dist_from_start[u]);
    }
    for (int i = 0; i < n; ++i) {
        int answer = min({dist_from_start[n - 1],          // don't use any (i<->undetermined) edges
                          dist_from_start[i] + 1 + min_to, // 0->i->undetermined->n-1
                          min_from + 1 + dist_to_end[i],   // 0->undetermined->i->n-1
                          min_from + 1 + min_to + 1});     // 0->undetermined->i->undetermined->n-1
        cout << (answer == INF ? -1 : answer) << " ";
    }
    return 0;
}