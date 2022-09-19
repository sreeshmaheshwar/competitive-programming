#include <bits/stdc++.h>
using namespace std;

struct directed_graph {
    vector<vector<int>> adj;
    vector<int> in_degree;
    int num_nodes;
 
    directed_graph(int n) : num_nodes(n) {
        adj.assign(num_nodes, {});
        in_degree.assign(num_nodes, 0);
    }
 
    void add_edge(int i, int j) {
        adj[i].push_back(j);
        in_degree[j]++;
    }
 
    pair<bool, vector<int>> topo_sort() {
        vector<int> order;
        for (int i = 0; i < num_nodes; ++i)
            if (!in_degree[i])
                order.push_back(i);

        for (int i = 0; i < (int) order.size(); ++i) {
            for (int j : adj[order[i]]) {
                in_degree[j]--;
                if (!in_degree[j])
                    order.push_back(j);
            }
        }
        return make_pair((int) order.size() == num_nodes, order);
    }
};

/*
Example main program, solution to:
https://cses.fi/problemset/task/1679 
*/

int main() {
    int n, m;
    cin >> n >> m;
    directed_graph graph(n);
    while (m--) {
        int a, b;
        cin >> a >> b;
        graph.add_edge(a - 1, b - 1);
    }
    auto [is_possible, topo_sort] = graph.topo_sort();
    if (is_possible) {
        for (int node : topo_sort) cout << node + 1 << " ";
    } else {
        cout << "IMPOSSIBLE";
    }
    return 0;
}
