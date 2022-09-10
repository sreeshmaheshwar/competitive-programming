#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, X;
    cin >> N >> X;
    cout << char((X - 1) / N + 'A') << endl;
    return 0;
}