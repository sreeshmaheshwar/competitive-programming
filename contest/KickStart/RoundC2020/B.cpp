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
        for (int i = 0; i < num_nodes; ++i) {
            if (!in_degree[i]) {
                order.push_back(i);
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
        return {(int) order.size() == num_nodes, order};
    }
};

void solve() {
    int R, C;
    cin >> R >> C;
    vector<string> grid(R);
    map<char, int> get_id;
    map<int, char> get_letter;
    int num_letters = 0;
    for (int i = 0; i < R; ++i) {
        cin >> grid[i];
        for (const char& letter : grid[i]) {
            if (!get_id.count(letter)) {
                get_id[letter] = num_letters;
                get_letter[num_letters] = letter;
                num_letters++;
            }
        }
    }
    directed_graph graph(num_letters);
    auto add_edge = [&](char a, char b) {
        graph.add_edge(get_id[a], get_id[b]);
    };
    for (int i = 0; i + 1 < R; ++i) {
        for (int j = 0; j < C; ++j) {
            int above = grid[i][j], below = grid[i + 1][j];
            if (above != below) {
                add_edge(below, above); // polyomino below must be built before one above
            }
        }
    }
    auto [possible, order] = graph.topo_sort();
    if (possible) {
        for (const int& node : order) {
            cout << get_letter[node];
        }
    } else {
        cout << -1;
    }
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

