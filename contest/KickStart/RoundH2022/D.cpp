#include <bits/stdc++.h>
using namespace std;

struct union_find {
  private:
    vector<int> sizes;
    vector<int> link;
    int n;

  public:
    union_find(int _n) : sizes(_n, 1), link(_n), n(_n) {
        iota(link.begin(), link.end(), 0);
    }

    int find(int x) {
        return x == link[x] ? x : link[x] = find(link[x]);
    }

    bool unite(int x, int y) {
        x = find(x), y = find(y);
        if (x != y) {
            if (sizes[x] > sizes[y]) swap(x, y);
            sizes[y] += sizes[x];
            link[x] = y;
            return true;
        }
        return false;
    }

    int size(int x) {
        return sizes[x];
    }
};

int main() {
    int tests;
    cin >> tests;

    for (int test = 1; test <= tests; ++test) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) 
            cin >> a[i], a[i]--;

        union_find uf(n);
        for (int i = 0; i < n; ++i) 
            uf.unite(i, a[i]);

        vector<int> sizes;
        for (int i = 0; i < n; ++i)
            if (i == uf.find(i))
                sizes.push_back(uf.size(i));

        sort(sizes.begin(), sizes.end(), greater<int>());

        vector<int> pref = {0}, size_freq(n + 1);
        for (int s : sizes) {
            pref.push_back(pref.back() + s);
            size_freq[s]++;
        }
        
        vector<int> min_subset(n + 1, n + 2);
        min_subset[0] = 0;
        for (int s = 1; s <= n; ++s) {
            if (!size_freq[s]) continue;
            auto new_min_subset = min_subset;
            for (int i = 0; i < s; ++i) {
                deque<pair<int, int>> dq;
                for (int j = i, k = 0; j <= n; j += s, ++k) {
                    while (!dq.empty() && dq.front().second < k - size_freq[s]) 
                        dq.pop_front();

                    if (!dq.empty())
                        new_min_subset[j] = min(new_min_subset[j], dq.front().first + k);

                    while (!dq.empty() && dq.back().first >= min_subset[j] - k)
                        dq.pop_back();

                    dq.emplace_back(min_subset[j] - k, k);
                }
            }
            min_subset = new_min_subset;
        }
        
        cout << "Case #" << test << ": ";
        for (int i = 1; i <= n; ++i)
            cout << min(int(lower_bound(pref.begin() + 1, pref.end(), i) - pref.begin()), min_subset[i] - 1) << " ";

        cout << '\n';
    }

    return 0;
}
