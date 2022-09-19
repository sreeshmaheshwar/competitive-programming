#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

template<typename T> struct kth_sum_tree {
  private:
    multiset<T> chosen;
    multiset<T> cands;
    int k;
    T sum;
  public:
    kth_sum_tree(int _k) : k(_k), sum(T(0)) {}
    void insert(T x) {
        if ((int) chosen.size() < k) {
            sum += x;
            chosen.insert(x);
        } else if (x < *chosen.rbegin()) {
            sum -= *chosen.rbegin();
            cands.insert(*chosen.rbegin());
            chosen.erase(prev(chosen.end()));
            sum += x;
            chosen.insert(x);
        } else {
            cands.insert(x);
        }
    }
    void erase(T x) {
        auto it = chosen.find(x);
        if (it == chosen.end()) {
            it = cands.find(x);
            assert(it != cands.end());
            cands.erase(it);
        } else {
            sum -= *it;
            chosen.erase(it);
            if (!cands.empty()) {
                sum += *cands.begin();
                chosen.insert(*cands.begin());
                cands.erase(cands.begin());
            }
        }
    }
    T kth_sum() const {
        return sum;
    }
};

void solve() {
    int n, k, x, d, m;
    cin >> n >> k >> x >> d >> m;
    vector<int> meeting_cnt(n);
    vector<vector<int>> starts_at(d + 1), ends_at(d + 1);
    while (m--) {
        int p, l, r;
        cin >> p >> l >> r;
        p--;
        if (l < x) meeting_cnt[p]++;
        starts_at[l].push_back(p);
        ends_at[r].push_back(p);
    }
    kth_sum_tree<int> tree(k);
    int ans = INF;
    for (int i = 0; i < n; ++i) {
        tree.insert(meeting_cnt[i]);
    }
    for (int i = 0; i + x <= d; ++i) {
        ans = min(ans, tree.kth_sum());
        for (int p : ends_at[i + 1]) {
            tree.erase(meeting_cnt[p]);
            meeting_cnt[p]--;
            tree.insert(meeting_cnt[p]);
        }
        for (int p : starts_at[i + x]) {
            tree.erase(meeting_cnt[p]);
            meeting_cnt[p]++;
            tree.insert(meeting_cnt[p]);
        }
    }
    cout << ans << '\n';
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