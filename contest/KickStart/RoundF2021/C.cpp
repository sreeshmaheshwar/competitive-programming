#include <bits/stdc++.h>
using namespace std;
const double INF = 1e9;

struct point {
	long long x, y;

	point() {}
	point(long long _x, long long _y) : x(_x), y(_y) {}

	void read() {
		std::cin >> x >> y;
	}

	point operator-(const point &p) const {
		return point(x - p.x, y - p.y);
	}
	void operator-=(const point &p) {
		x -= p.x;
		y -= p.y;
	}

	long long cross_product(const point &p) {
		return x * p.y - y * p.x;
	}
	
	double distance(const point &p) {
		return std::hypot(x - p.x, y - p.y);
	}
};

void solve() {
	int n; 
	cin >> n;
	vector<point> points(n);
	for (point &star : points) {
		star.read();
	}
	point blue_star;
	blue_star.read();
	for (point &star : points) {
		star -= blue_star;
	}
	vector<vector<double>> dist(n, vector<double>(n));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (points[i].cross_product(points[j]) > 0) {
				dist[i][j] = points[i].distance(points[j]);
			} else {
				dist[i][j] = INF;
			}
		}
	}
	for (int k = 0; k < n; ++k) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	double ans = INF;
	for (int i = 0; i < n; ++i) {
		ans = min(ans, dist[i][i]);
	}
	cout << (ans == INF ? "IMPOSSIBLE" : to_string(ans)) << '\n';
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