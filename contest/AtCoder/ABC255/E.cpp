#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> S(N - 1), X(M);
    for (int &element : S) cin >> element;
    for (int &element : X) cin >> element;
    map<long long, int> cnt;
    for (int i = 0; i < M; ++i) {
        cnt[X[i]]++;
    }
    long long prefix_sum = 0;
    for (int i = 0; i < N - 1; ++i) {
        prefix_sum += (i % 2 == 0 ? +1 : -1) * S[i];
        for (int j = 0; j < M; ++j) {
            long long start = prefix_sum + (i % 2 == 0 ? -1 : +1) * X[j];
            cnt[start]++;
        }
    }
    int answer = 0;
    for (auto entry : cnt) answer = max(answer, entry.second);
    cout << answer << endl;
    return 0;
}