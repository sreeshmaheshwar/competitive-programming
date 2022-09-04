#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    long long k;
    cin >> k;

    int num_chars = a + b;
    vector<vector<long long>> choose(num_chars + 1, vector<long long>(num_chars + 1)); // binomial coefficient, N choose R
    choose[0][0] = 1;
    for (int i = 1; i <= num_chars; ++i) {
        choose[i][0] = choose[i][i] = 1;
        for (int j = 1; j < i; ++j) {
            choose[i][j] = choose[i - 1][j] + choose[i - 1][j - 1];
        }
    }

    string answer;
    for (int iter = 0; iter < num_chars; ++iter) {
        if (k <= choose[a + b - 1][b]) {
            answer += 'a';
            a--;
        } else {
            answer += 'b';
            k -= choose[a + b - 1][b];
            b--;
        }
    }
    cout << answer << endl;
    return 0;
}