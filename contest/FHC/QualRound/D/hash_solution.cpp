/* takes 17 seconds to run locally */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
const int ROOT = 448;

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<pair<int, int>>> adj(n);
    vector<gp_hash_table<int, int>> weight(n);
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        adj[a].emplace_back(b, c);
        adj[b].emplace_back(a, c);
        weight[a][b] = weight[b][a] = c;
    }
    vector<gp_hash_table<int, long long>> heavy_answer(n);
    auto two_path_dfs = [&](int u) -> void {
        for (const auto &[node, w1] : adj[u]) {
            for (const auto &[v, w2] : adj[node]) {
                heavy_answer[u][v] += min(w1, w2);
            }
        }
    };
    vector<bool> is_heavy(n, false);
    for (int i = 0; i < n; ++i) {
        if (adj[i].size() > ROOT) {
            is_heavy[i] = true;
            two_path_dfs(i);
        }
    }
    while (q--) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        long long answer = weight[a][b] * 2;
        if (is_heavy[a]) {
            answer += heavy_answer[a][b];
        } else if (is_heavy[b]) {
            answer += heavy_answer[b][a];
        } else {
            for (const auto &[node, w] : adj[a]) {
                answer += min(w, weight[b][node]);
            }
        }
        cout << answer << " \n"[!q];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for (int test_case = 1; test_case <= T; ++test_case) {
        cerr << "Doing Case #" << test_case << endl;
        cout << "Case #" << test_case << ": ";
        solve();
    }
    return 0;
}