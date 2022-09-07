#include <bits/stdc++.h>
using namespace std;

long long to_decimal(string s, int base) {
    long long power = 1, answer = 0;
    while (!s.empty()) {
        answer += (s.back() - '0') * power;
        s.pop_back();
        power *= base;
    }
    return answer;
}

int main() {
    int K;
    cin >> K;
    string A, B;
    cin >> A >> B;
    cout << to_decimal(A, K) * to_decimal(B, K) << endl;
    return 0;
}