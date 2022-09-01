#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(K);
    for (int i = 0; i < K; ++i) {
        cin >> A[i];
        A[i]--;
    }
    vector<int> X(N), Y(N);
    for (int i = 0; i < N; ++i) {
        cin >> X[i] >> Y[i];
    }
    double answer = 0;
    for (int i = 0; i < N; ++i) {
        double current = INFINITY;
        for (int j : A) {
            current = min(current, hypot(X[i] - X[j], Y[i] - Y[j]));
        }
        answer = max(answer, current);
    }
    cout << fixed << setprecision(12) << answer << endl;
    return 0;
}