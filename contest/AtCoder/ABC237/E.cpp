#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <utility>

constexpr int64_t INF = 1e18;

std::vector<int64_t> dijkstra(const std::vector<std::vector<std::pair<int, int>>>& adj, int start_node) {
    int n = adj.size();
    
    std::priority_queue<std::pair<int64_t, int>, std::vector<std::pair<int64_t, int>>, std::greater<>> q;
    std::vector<int64_t> dist(n, INF);
    std::vector<bool> processed(n, false);

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

int main() {
	int n, m; 
	std::cin >> n >> m;

	std::vector<int> h(n);
	for (int i = 0; i < n; ++i)
		std::cin >> h[i];

	auto get_weight = [&](int x, int y) -> int {
		return std::max(0, h[y] - h[x]);
	};

	std::vector<std::vector<std::pair<int, int>>> adj(n);
	for (int i = 0; i < m; ++i) {
		int x, y; 
		std::cin >> x >> y; 
		x--, y--;
		adj[x].emplace_back(y, get_weight(x, y));
		adj[y].emplace_back(x, get_weight(y, x));
	}

	const auto dist = dijkstra(adj, 0);

	int64_t ans = 0;
	for (int i = 0; i < n; ++i)
		ans = std::max(ans, -(dist[i] + h[i] - h[0]));

	std::cout << ans;
	return 0;
}