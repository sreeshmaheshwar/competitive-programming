#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;
    int answer = (B / C) * C;
    cout << (answer >= A ? answer : -1) << '\n';
    return 0;
}