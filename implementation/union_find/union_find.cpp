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

/*
Example Main Program:
(solution to https://atcoder.jp/contests/abc177/tasks/abc177_d)
*/

int main() { 
    int n, m;
    std::cin >> n >> m;

    union_find UF(n);
    for (int i = 0, a, b; i < m; ++i) {
        std::cin >> a >> b, a--, b--;
        UF.unite(a, b);
    }
    
    int ans = 0;
    for (int i = 0; i < n; ++i) 
        ans = std::max(ans, UF.size(i));

    std::cout << ans << std::endl;
    return 0;
}