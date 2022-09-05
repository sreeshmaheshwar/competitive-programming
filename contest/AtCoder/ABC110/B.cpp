#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int N, M, X, Y;
    std::cin >> N >> M >> X >> Y;
    X++; // make inclusive
    std::vector<int> x(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> x[i];
    }
    std::vector<int> y(M);
    for (int i = 0; i < M; ++i) {
        std::cin >> y[i];
    }
    int min_Z = *std::max_element(x.begin(), x.end()) + 1;
    int max_Z = *std::min_element(y.begin(), y.end());
    std::cout << (min_Z > max_Z || max_Z < X || min_Z > Y ? "War" : "No War") << std::endl;
    return 0;
}