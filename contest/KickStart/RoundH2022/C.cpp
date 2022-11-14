#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int test_case = 1; test_case <= T; ++test_case) {
        int N;
        cin >> N;

        vector<pair<int, int>> A(N);
        for (int i = 0; i < N; ++i) {
            cin >> A[i].first;
            A[i].second = i;
        }

        vector<vector<int>> adj(N);
        for (int i = 0, a, b; i < N - 1; ++i) {
            cin >> a >> b, a--, b--;
            if (A[a].first > A[b].first) adj[a].push_back(b);
            else if (A[a].first < A[b].first) adj[b].push_back(a);
        }

        sort(A.begin(), A.end());

        vector<int> max_junctions(N, 1);
        for (auto [_, i] : A)
            for (int j : adj[i])
                max_junctions[i] += max_junctions[j];

        cout << "Case #" << test_case << ": " << *max_element(max_junctions.begin(), max_junctions.end()) << '\n';
    }
    return 0;
}