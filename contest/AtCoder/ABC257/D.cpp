#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> x(n), y(n), p(n);
    for (int i = 0; i < n; ++i)
        cin >> x[i] >> y[i] >> p[i];
    // adapted Floyd-Warshall algorithm
    vector<vector<long long>> dist(n, vector<long long>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            dist[i][j] = (abs(x[i] - x[j]) + abs(y[i] - y[j]) + p[i] - 1) / p[i];
    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                dist[i][j] = min(dist[i][j], max(dist[i][k], dist[k][j]));
    // iterate over chosen node (from which all others should be reachable)
    long long answer = 1e18;
    for (int i = 0; i < n; ++i) {
        long long min_training_required = 0;
        for (int j = 0; j < n; ++j)
            min_training_required = max(min_training_required, dist[i][j]);
        answer = min(answer, min_training_required);
    }
    cout << answer << endl;
    return 0;
}