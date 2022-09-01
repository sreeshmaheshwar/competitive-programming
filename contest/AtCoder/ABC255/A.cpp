#include <bits/stdc++.h>
using namespace std;

int main() {
    int R, C;
    cin >> R >> C;
    for (int i = 1; i <= 2; ++i) {
        for (int j = 1; j <= 2; ++j) {
            int A;
            cin >> A;
            if (i == R && j == C) {
                cout << A << endl;
            }
        }
    }
    return 0;
}