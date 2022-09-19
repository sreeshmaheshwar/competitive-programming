#include <bits/stdc++.h>
using namespace std;

struct seed {
    long long q, l, v;

    bool operator<(const seed& other) const {
        return l < other.l;
    }
};

void solve() {
    long long d, n, x;
    cin >> d >> n >> x;
    vector<seed> seeds(n);
    for (seed& s : seeds)
        cin >> s.q >> s.l >> s.v;
    sort(seeds.begin(), seeds.end());

    long long answer = 0;
    priority_queue<pair<long long, long long>> pq;
    for (int i = 0; i < n; ++i) {
        pq.emplace(seeds[i].v, seeds[i].q);
        long long to_plant = x * ((i == n - 1 ? d : seeds[i + 1].l) - seeds[i].l);
        while (!pq.empty()) {
            auto [v, q] = pq.top();
            pq.pop();
            if (q < to_plant) {
                to_plant -= q;
                answer += q * v;
            } else {
                answer += to_plant * v;
                q -= to_plant;
                if (q > 0) pq.emplace(v, q);
                break;
            }
        }
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