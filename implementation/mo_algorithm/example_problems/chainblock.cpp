#include <bits/stdc++.h>
using namespace std;

class Query {
  private:
    int64_t ord;
    
    inline int64_t gilbertOrder(int x, int y, int pow, int rotate) { // credited to https://codeforces.com/blog/entry/61203
        if (pow == 0) {
            return 0;
        }
        int hpow = 1 << (pow-1);
        int seg = (x < hpow) ? (
            (y < hpow) ? 0 : 3
        ) : (
            (y < hpow) ? 1 : 2
        );
        seg = (seg + rotate) & 3;
        const int rotateDelta[4] = {3, 0, 0, 1};
        int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
        int nrot = (rotate + rotateDelta[seg]) & 3;
        int64_t subSquareSize = int64_t(1) << (2*pow - 2);
        int64_t ans = seg * subSquareSize;
        int64_t add = gilbertOrder(nx, ny, pow-1, nrot);
        ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
        return ans;
    }

    inline void calcOrder() {
        ord = gilbertOrder(l, r, 21, 0);
    }

  public:
    int l, r;

    Query() {}

    Query(int _l, int _r) : l(_l), r(_r) {
        calcOrder();
    }

    inline bool operator<(const Query &q) const {
        return ord < q.ord;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int timer = 0;
    vector<int> pre_order(n);
    vector<int> time_in(n), time_out(n);
    function<void(int, int)> dfs = [&](int u, int par) {
        pre_order[timer] = u;
        time_in[u] = timer++;
        for (int v : adj[u]) 
            if (v != par)
                dfs(v, u);
        time_out[u] = timer;
    };
    dfs(0, -1);

    vector<int> f(n);
    vector<int> f_cnt(n);
    for (int i = 0; i < n; ++i) {
        cin >> f[i];
        f[i]--;
        f_cnt[f[i]]++;
    }
    vector<int> a(n);
    for (int i = 0; i < n; ++i) 
        a[i] = f[pre_order[i]];

    vector<Query> queries;
    for (int i = 1; i < n; ++i)
        queries.push_back({time_in[i], time_out[i] - 1});
    sort(queries.begin(), queries.end());

    vector<int> cnt(n);
    int num_bad = 0;

    auto add = [&](int i) {
        if (!cnt[a[i]]) num_bad++;
        cnt[a[i]]++;
        if (cnt[a[i]] == f_cnt[a[i]]) num_bad--;
    };

    auto remove = [&](int i) {
        if (cnt[a[i]] == f_cnt[a[i]]) num_bad++;
        cnt[a[i]]--;
        if (!cnt[a[i]]) num_bad--;
    };

    int l = 0, r = -1, ans = 0;
    for (const Query &query : queries) {
        while (l > query.l) {
            l--;
            add(l);
        }
        while (r < query.r) {
            r++;
            add(r);
        }
        while (l < query.l) {
            remove(l);
            l++;
        }
        while (r > query.r) {
            remove(r);
            r--;
        }
        if (!num_bad) ans++;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int test_case = 1; test_case <= T; ++test_case) {
        cerr << "Doing Case #" << test_case << endl;
        cout << "Case #" << test_case << ": ";
        solve();
    }
    
    return 0;
}