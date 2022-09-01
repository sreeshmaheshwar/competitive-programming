#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> P(N);
    for (int i = 0; i < N; ++i) {
        cin >> P[i];
    }
    vector<int> I(N);
    vector<int> position(N + 1);
    for (int i = 0; i < N; ++i) {
        cin >> I[i];
        position[I[i]] = i;
    }
    int i = 0;
    vector<int> L(N + 1, 0), R(N + 1, 0);
    function<void(int, int, int)> find_tree = [&](int root, int left, int right) {
        i++;
        if (i < N && left <= position[P[i]] && position[P[i]] < position[root]) {
            L[root] = P[i];
            find_tree(P[i], left, position[root] - 1);
        }
        if (i < N && position[P[i]] > position[root] && position[P[i]] <= right) {
            R[root] = P[i];
            find_tree(P[i], position[root] + 1, right);
        }
    };
    find_tree(1, 0, N - 1);
    if (i < N) {
        cout << -1 << '\n';
    } else {
        for (int j = 1; j <= N; ++j) {
            cout << L[j] << " " << R[j] << '\n';
        }
    }
    return 0;
}