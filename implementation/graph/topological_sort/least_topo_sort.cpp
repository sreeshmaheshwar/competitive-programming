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

    pair<bool, vector<int>> lexicographically_least_topo_sort() {
        vector<int> order;
        priority_queue<int, vector<int>, greater<>> pq;
        for (int i = 0; i < num_nodes; ++i) {
            if (!in_degree[i]) {
                pq.push(i);
            }
        }
        while (!pq.empty()) {
            int node = pq.top();
            pq.pop();
            order.push_back(node);
            for (int neighbour : adj[node]) {
                in_degree[neighbour]--;
                if (!in_degree[neighbour]) {
                    pq.push(neighbour);
                }
            }
        }
        return {(int) order.size() == num_nodes, order};
    }
};

/* 
Example main program, solution to:
https://atcoder.jp/contests/abc223/tasks/abc223_d
*/

int main() {
    int N, M;
    cin >> N >> M;
    directed_graph graph(N);
    while (M--) {
        int A, B;
        cin >> A >> B;
        graph.add_edge(A - 1, B - 1);
    }
    auto [possible, order] = graph.lexicographically_least_topo_sort();
    if (possible) {
        for (int node : order) {
            cout << node + 1 << " ";
        }
    } else {
        cout << -1;
    }
    return 0;
}