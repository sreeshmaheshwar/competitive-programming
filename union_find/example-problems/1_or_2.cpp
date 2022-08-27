#include <bits/stdc++.h>
using namespace std;

/*
Solution to:
https://atcoder.jp/contests/abc126/tasks/abc126_e
*/

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
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    union_find uf(n);
    for (int i = 0; i < m; ++i) {
        int x, y, _;
        cin >> x >> y >> _;
        uf.unite(x - 1, y - 1);
    }
    cout << uf.count() << endl;

    return 0;
}