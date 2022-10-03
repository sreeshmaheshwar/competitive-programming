#include <bits/stdc++.h>
using namespace std;

constexpr long long INF = (long long) 1e18;

struct point {
    long long x, y;

    long long square_dist(const point& p) const {
        return (x - p.x) * (x - p.x) + (y - p.y) * (y - p.y);
    }

    bool operator<(const point& p) const {
        return x < p.x;
    }
};

namespace convex_hull { // adapted from https://cp-algorithms.com/geometry/convex-hull.html#implementation
    int get_orientation(const point& a, const point& b, const point& c) {
        long long C = a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y);
        if (C < 0) 
        	return -1;
        if (C > 0) 
        	return +1;
        return 0;
    }

    bool clockwise(const point& a, const point& b, const point& c, bool include_collinear) {
        int orientation = get_orientation(a, b, c);
        return orientation < 0 || (include_collinear && !orientation);
    }

    bool collinear(const point& a, const point& b, const point& c) {
        return !get_orientation(a, b, c);
    }
    
    void convex_hull(vector<point>& points, bool include_collinear = false) {
        point base_point = *min_element(points.begin(), points.end(), [](const point& a, const point& b) {
            return make_pair(a.y, a.x) < make_pair(b.y, b.x);
        });

        sort(points.begin(), points.end(), [&base_point](const point& a, const point& b) {
            int orientation = get_orientation(base_point, a, b);
            if (orientation == 0) {
                return (base_point.x - a.x) * (base_point.x - a.x) + (base_point.y - a.y) * (base_point.y - a.y)
                     < (base_point.x - b.x) * (base_point.x - b.x) + (base_point.y - b.y) * (base_point.y - b.y);
            }
            return orientation < 0;
        });

        if (include_collinear) {
            int i = (int) points.size() - 1;
            while (i >= 0 && collinear(base_point, points[i], points.back()))
            	i--;
            reverse(points.begin() + i + 1, points.end());
        }

        vector<point> hull;
        for (int i = 0; i < (int) points.size(); i++) {
            while (hull.size() > 1 && !clockwise(hull[hull.size() - 2], hull.back(), points[i], include_collinear))
                hull.pop_back();
            hull.push_back(points[i]);
        }
        points = hull;
    }
}

long long solve() {
    int n;
    cin >> n;
    long long k, d;
    cin >> k >> d;
    vector<point> points(n);
    for (auto& [x, y] : points)
        cin >> x >> y;

    convex_hull::convex_hull(points);
    sort(points.begin(), points.end());
    n = points.size();

    vector<long long> dist(n, INF);
    dist[0] = 0;
    vector<bool> visited(n, false);
    for (int iter = 0; iter < n; ++iter) {
        int node = -1;
        for (int i = 0; i < n; ++i)
            if (!visited[i] && (node == -1 || dist[i] < dist[node]))
                node = i;

        visited[node] = true;
        for (int i = 0; i < n; ++i)
            if (points[node].square_dist(points[i]) <= d * d)
                dist[i] = min(dist[i], dist[node] + max(k, points[node].square_dist(points[i])));
   }
   return dist.back() == INF ? -1 : dist.back();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int test_case = 1; test_case <= T; ++test_case) {
        cerr << "Doing Case #" << test_case << endl;
        cout << "Case #" << test_case << ": " << solve() << '\n';
    }
    
    return 0;
}