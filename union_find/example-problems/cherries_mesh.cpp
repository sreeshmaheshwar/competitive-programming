#include <bits/stdc++.h>
using namespace std;

/* Solution to https://codingcompetitions.withgoogle.com/kickstart/round/0000000000050edb/0000000000170721 */

struct union_find {
  private:
    int cnt;
    vector<int> sizes, link;
 
  public:
    union_find() {}
  
    union_find(int n) : cnt(n), sizes(n, 1), link(n, 0) { iota(link.begin(), link.end(), 0); }
  
    int find(int x) { return x == link[x] ? x : link[x] = find(link[x]); }
  
    bool same(int x, int y) { return find(x) == find(y); }
  
    void unite(int x, int y) {
      x = find(x); y = find(y);
      if (x == y) return;
      if (sizes[x] < sizes[y]) 
        swap(x, y);
      
      sizes[x] += sizes[y];
      link[y] = x;
      cnt--;
    }
  
    int size(int x) { return sizes[find(x)]; }
  
    int count() const { return cnt; }	
};

int main() {
    int T; 
    scanf("%d\n", &T);
    for (int test_case = 1; test_case <= T; ++test_case) {
        int n, m;
        scanf("%d %d", &n, &m);
        union_find uf(n);
        for (int i = 0; i < m; ++i) {
            int c, d;
            scanf("%d %d", &c, &d);
            c--, d--;
            uf.unite(c, d);
        }
        printf("Case #%d: %d\n", test_case, n + uf.count() - 2);
    }
    return 0;
}
