#include <bits/stdc++.h>

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

int main() {
    std::vector<point> ps(4);
    for (point& p : ps) p.read();
    bool convex = true;
    for (int i = 0; i < 4; ++i) {
        if ((ps[(i + 1) % 4] - ps[i]).cross_product(ps[(i + 2) % 4] - ps[(i + 1) % 4]) < 0) {
            convex = false;
        }
    }
    std::cout << (convex ? "Yes" : "No") << std::endl;
    return 0;
}