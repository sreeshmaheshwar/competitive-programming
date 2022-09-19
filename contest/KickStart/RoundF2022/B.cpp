#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a - 1].push_back(b - 1);
        adj[b - 1].push_back(a - 1);
    }
    for (int iter = 0; iter < q; ++iter) {
        int _;
        cin >> _;
    }

    vector<int> depth_cnt(n, 0);
    function<void(int, int, int)> dfs = [&](int node, int parent, int depth) {
        depth_cnt[depth]++;
        for (int neighbour : adj[node])
            if (neighbour != parent)
                dfs(neighbour, node, depth + 1);
    };
    dfs(0, -1, 0);

    int answer = 0;
    for (int depth = 0; depth < n && q >= depth_cnt[depth]; ++depth) {
        answer += depth_cnt[depth];
        q -= depth_cnt[depth];
    }
    cout << answer << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int test_case = 1; test_case <= T; ++test_case) {
        cout << "Case #" << test_case << ": ";
        solve();
    }
    
    return 0;
}