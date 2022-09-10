#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    vector<int> W(N), children, adults;
    for (int i = 0; i < N; ++i) {
        cin >> W[i];
        (S[i] == '0' ? children : adults).push_back(W[i]);
    }
    sort(children.begin(), children.end()), sort(adults.begin(), adults.end());
    auto F = [&](int X) -> int {
        return distance(children.begin(), lower_bound(children.begin(), children.end(), X))
               + distance(lower_bound(adults.begin(), adults.end(), X), adults.end());
    };
    int answer = F(0);
    for (int child_weight : children) {
        answer = max(answer, F(child_weight + 1));
    }
    cout << answer << endl;
    return 0;
}