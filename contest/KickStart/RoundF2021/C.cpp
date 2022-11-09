#include <bits/stdc++.h>
using namespace std;

constexpr double INF = 1e9;

struct point {
  private:
    int x, y;

    friend istream& operator>>(istream& is, point& p) {
        return is >> p.x >> p.y;
    }

  public:
    void operator-=(const point& other) {
        x -= other.x, y -= other.y;
    }

    int64_t operator*(const point& other) const {
        return int64_t(x) * other.y - int64_t(other.x) * y;
    }

    double distance(const point& other) const {
        return hypot(x - other.x, y - other.y);
    }
};

string solve() {
    int n;
    cin >> n;

    vector<point> points(n);
    for (point& p : points) 
        cin >> p;

    point blue;
    cin >> blue;

    for (point& p : points) 
        p -= blue;

    vector<vector<double>> dist(n, vector<double>(n, INF + 10));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (points[i] * points[j] > 0)
                dist[i][j] = points[i].distance(points[j]);

    for (int k = 0; k < n; ++k) 
        for (int i = 0; i < n; ++i) 
            for (int j = 0; j < n; ++j) 
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            
    double ans = INF + 10;
    for (int i = 0; i < n; ++i) 
        ans = min(ans, dist[i][i]);

    return (ans >= INF ? "IMPOSSIBLE" : to_string(ans));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int test_case = 1; test_case <= T; ++test_case)
        cout << "Case #" << test_case << ": " << solve() << '\n';
    
    return 0;
}