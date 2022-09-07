#include <bits/stdc++.h>
using namespace std;

struct directed_graph {
    vector<vector<int>> adj;
    vector<int> in_degree;
    vector<bool> present;
    int num_nodes;

    directed_graph(int n) : num_nodes(n) {
        adj.assign(num_nodes, {});
        in_degree.assign(num_nodes, 0);
        present.assign(num_nodes, 0);
    }

    void add_edge(int i, int j) {
        adj[i].push_back(j);
        in_degree[j]++;
    }

    pair<bool, vector<int>> topo_sort() {
        vector<int> order;
        int node_count = 0;
        for (int i = 0; i < num_nodes; ++i) {
            if (present[i]) {
                node_count++;
                if (!in_degree[i]) {
                    order.push_back(i);
                }
            }
        }
        for (int i = 0; i < (int) order.size(); ++i) {
            for (int j : adj[order[i]]) {
                in_degree[j]--;
                if (!in_degree[j]) {
                    order.push_back(j);
                }
            }
        }
        return {(int) order.size() == node_count, order};
    }
};

void solve() {
    int R, C;
    cin >> R >> C;
    vector<string> grid(R);
    directed_graph graph(26);
    for (int i = 0; i < R; ++i) {
        cin >> grid[i];
        for (const char& c: grid[i]) 
            graph.present[c - 'A'] = true;
    }
    for (int i = 0; i + 1 < R; ++i)
        for (int j = 0; j < C; ++j)
            if (grid[i][j] != grid[i + 1][j])
                graph.add_edge(grid[i + 1][j] - 'A', grid[i][j] - 'A');
    auto [possible, order] = graph.topo_sort();
    if (possible)
        for (const int& node : order) 
            cout << char(node + 'A');
    else
        cout << -1;
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for (int test_case = 1; test_case <= T; ++test_case) {
        cout << "Case #" << test_case << ": ";
        solve();
    }
    return 0;
}

