#include <bits/stdc++.h>
using namespace std;
const string MORSE_CHARS = "-.";

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for (int test_case = 1; test_case <= T; ++test_case) {
        int N;
        cin >> N;
        string C;
        cin >> C;
        cout << "Case #" << test_case << ":\n";
        for (int i = 0; i < N - 1; ++i) {
            cout << MORSE_CHARS[C[0] == MORSE_CHARS[0]];
            for (int j = 0; j < 9; ++j) {
                cout << MORSE_CHARS[i >> j & 1];
            }
            cout << '\n';
        }
    }
    return 0;
}