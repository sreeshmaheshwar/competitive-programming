/* this solution does not rely on the constraint on D */
#include <bits/stdc++.h>
using namespace std;

struct event {
    int event_time, index;
    bool is_end;

    bool operator<(const event &e) const {
        if (event_time == e.event_time) {
            return is_end > e.is_end;
        }
        return event_time < e.event_time;
    }
};

void solve() {
    int d, n, k;
    cin >> d >> n >> k;
    vector<int> h(n), s(n), e(n);
    vector<event> events;
    for (int i = 0; i < n; ++i) {
        cin >> h[i] >> s[i] >> e[i];
        events.push_back({s[i], i, false});
        events.push_back({e[i] + 1, i, true});
    }
    sort(events.begin(), events.end());
    set<pair<int, int>> chosen, candidates;
    long long answer = 0, current_max_happiness = 0;
    for (auto [_, i, is_end] : events) {
        if (!is_end) {
            if ((int) chosen.size() < k) {
                chosen.insert({h[i], i});
                current_max_happiness += h[i];
            } else {
                int j = chosen.begin()->second;
                if (h[i] > h[j]) {
                    chosen.erase({h[j], j}), candidates.insert({h[j], j});
                    current_max_happiness -= h[j];
                    chosen.insert({h[i], i});
                    current_max_happiness += h[i];
                } else {
                    candidates.insert({h[i], i});
                }
            }
        } else {
            if (chosen.count({h[i], i})) {
                chosen.erase({h[i], i});
                current_max_happiness -= h[i];
                if (!candidates.empty()) {
                    int j = candidates.rbegin()->second;
                    candidates.erase({h[j], j}), chosen.insert({h[j], j});
                    current_max_happiness += h[j];
                }
            } else {
                candidates.erase({h[i], i});
            }
        }
        answer = max(answer, current_max_happiness);
    }
    cout << answer << '\n';
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