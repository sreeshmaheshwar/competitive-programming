#include <bits/stdc++.h>
using namespace std;
constexpr long long INF = (long long) 1e18;

struct point {

	long long x, y;

	void read() {
		cin >> x >> y;
	}

	long long dist2(const point& p) const {
		return (x - p.x) * (x - p.x) + (y - p.y) * (y - p.y);
	}

	bool operator<(const point& p) const {
		return x < p.x;
	}
};

// from https://cp-algorithms.com/geometry/convex-hull.html#implementation
namespace convex_hull {

	int orientation(point a, point b, point c) {
	    long long v = a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y);
	    if (v < 0) return -1;
	    if (v > 0) return +1;
	    return 0;
	}

	bool cw(point a, point b, point c, bool include_collinear) {
	    int o = orientation(a, b, c);
	    return o < 0 || (include_collinear && o == 0);
	}

	bool collinear(point a, point b, point c) { return orientation(a, b, c) == 0; }
	
	void convex_hull(vector<point>& a, bool include_collinear = false) {
    	point p0 = *min_element(a.begin(), a.end(), [](point a, point b) {
	        return make_pair(a.y, a.x) < make_pair(b.y, b.x);
	    });
	    sort(a.begin(), a.end(), [&p0](const point& a, const point& b) {
	        int o = orientation(p0, a, b);
	        if (o == 0)
	            return (p0.x-a.x)*(p0.x-a.x) + (p0.y-a.y)*(p0.y-a.y)
	                < (p0.x-b.x)*(p0.x-b.x) + (p0.y-b.y)*(p0.y-b.y);
	        return o < 0;
	    });
	    if (include_collinear) {
	        int i = (int) a.size() - 1;
	        while (i >= 0 && collinear(p0, a[i], a.back())) i--;
	        reverse(a.begin() + i + 1, a.end());
	    }
	    vector<point> st;
	    for (int i = 0; i < (int) a.size(); i++) {
	        while (st.size() > 1 && !cw(st[st.size()-2], st.back(), a[i], include_collinear))
	            st.pop_back();
	        st.push_back(a[i]);
	    }
	    a = st;
	}
}

void solve() {
	int n;
	cin >> n;
	long long k, d;
	cin >> k >> d;
	vector<point> points(n);
	for (point& pt : points) {
		pt.read();
	}

	convex_hull::convex_hull(points);
	sort(points.begin(), points.end());
	n = points.size();

	vector<long long> dist(n, INF);
	dist[0] = 0;
	vector<bool> visited(n, false);
	for (int iter = 0; iter < n; ++iter) {
		int node = -1;
		for (int i = 0; i < n; ++i) {
			if (!visited[i] && (node == -1 || dist[i] < dist[node])) {
				node = i;
			}
		}
		if (node == -1) break;
		visited[node] = true;
		for (int i = 0; i < n; ++i) {
			if (points[node].dist2(points[i]) <= d * d) {
				dist[i] = min(dist[i], dist[node] + max(k, points[node].dist2(points[i])));
			}
		}
	}
	cout << (dist.back() == INF ? -1 : dist.back()) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int test_case = 1; test_case <= T; ++test_case) {
    	cerr << "Doing Case #" << test_case << endl;
        cout << "Case #" << test_case << ": ";
        solve();
    }
    
    return 0;
}