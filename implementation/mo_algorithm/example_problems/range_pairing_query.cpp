/*
Solution to:
https://atcoder.jp/contests/abc242/tasks/abc242_g
*/

#include <bits/stdc++.h>
using namespace std;

class Query {

  private:

    int64_t ord;

    // credited to https://codeforces.com/blog/entry/61203
    inline int64_t gilbertOrder(int x, int y, int pow, int rotate) {
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

    int l, r, index;

    Query() {}

    Query(int _l, int _r, int _index) : l(_l), r(_r), index(_index) {
        calcOrder();
    }

    inline bool operator<(const Query &q) const {
        return ord < q.ord;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i]--;
    }

    int q;
    cin >> q;
    vector<Query> queries(q);
    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        queries[i] = Query(l, r, i);
    }
    sort(queries.begin(), queries.end());

    vector<long long> cnt(n, 0);
    vector<long long> answers(q);
    long long answer = 0;

    auto add = [&](int i) {
        cnt[a[i]]++;
        if (cnt[a[i]] % 2 == 0) answer++;
    };
 
    auto remove = [&](int i) {
        if (cnt[a[i]] % 2 == 0) answer--;
        cnt[a[i]]--;
    };

    int l = 0, r = -1;
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
        answers[query.index] = answer;
    }

    for (auto query_answer : answers) {
        cout << query_answer << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    
    return 0;
}