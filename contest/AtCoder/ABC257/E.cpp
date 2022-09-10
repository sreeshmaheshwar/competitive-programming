#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> C(10);
    int min_cost = N + 1;
    for (int i = 1; i <= 9; ++i) {
        cin >> C[i];
        min_cost = min(min_cost, C[i]);
    }
    int len = N / min_cost;
    string answer = "";
    for (int i = 0; i < len; ++i) {
        for (int digit = 9; digit >= 1; --digit) {
            if (C[digit] + min_cost * (len - i - 1) <= N) {
                answer += digit + '0';
                N -= C[digit];
                break;
            }
        }
    }
    cout << answer << endl;
    return 0;
}