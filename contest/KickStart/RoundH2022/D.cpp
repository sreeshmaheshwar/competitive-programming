#include <bits/stdc++.h>

/* Description: Disjoint Set Union data structure, with
   path compression and union by size optimisations, to
   allow for near constant time (amortized) queries. */
struct union_find {
  private:
    int num_components;
    std::vector<int> sizes, link;

  public:
    union_find(int _num_components) : num_components(_num_components) {
        sizes.assign(num_components, 1);
        link.resize(num_components);
        std::iota(link.begin(), link.end(), 0);
    }

    int count() const { return num_components; }
    int size(int x) { return sizes[find(x)]; }
    int find(int x) { return x == link[x] ? x : link[x] = find(link[x]); }

    bool unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return false;
        /* Ensure that y is a smaller set than x. */
        if (sizes[x] < sizes[y]) std::swap(x, y);
        /* Merge y into x. */
        sizes[x] += sizes[y];
        link[y] = x;
        num_components--;
        return true;
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int tests;
    std::cin >> tests;

    for (int test = 1; test <= tests; ++test) {
        int n;
        std::cin >> n;

        std::vector<int> a(n);
        for (int i = 0; i < n; ++i) 
            std::cin >> a[i], a[i]--;

        union_find uf(n);
        for (int i = 0; i < n; ++i) 
            uf.unite(i, a[i]);

        std::vector<int> sizes;
        for (int i = 0; i < n; ++i)
            if (i == uf.find(i))
                sizes.push_back(uf.size(i));

        std::sort(sizes.begin(), sizes.end(), std::greater<int>());

        std::vector<int> pref = {0}, size_freq(n + 1);
        for (int s : sizes) {
            pref.push_back(pref.back() + s);
            size_freq[s]++;
        }
        
        std::vector<int> min_subset(n + 1, n + 2);
        min_subset[0] = 0;
        for (int s = 1; s <= n; ++s) {
            if (!size_freq[s]) continue;
            auto new_min_subset = min_subset;
            for (int i = 0; i < s; ++i) {
                std::deque<std::pair<int, int>> dq;
                for (int j = i, k = 0; j <= n; j += s, ++k) {
                    while (!dq.empty() && dq.front().second < k - size_freq[s]) 
                        dq.pop_front();

                    if (!dq.empty())
                        new_min_subset[j] = std::min(new_min_subset[j], dq.front().first + k);

                    while (!dq.empty() && dq.back().first >= min_subset[j] - k)
                        dq.pop_back();

                    dq.emplace_back(min_subset[j] - k, k);
                }
            }
            min_subset = new_min_subset;
        }
        
        std::cout << "Case #" << test << ": ";
        for (int i = 1; i <= n; ++i)
            std::cout << std::min(int(std::lower_bound(pref.begin() + 1, pref.end(), i) - pref.begin()), min_subset[i] - 1) << " ";

        std::cout << std::endl;
    }
}
