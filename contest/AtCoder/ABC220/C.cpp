#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    long long sum = 0;
    for (int &a : A) {
        cin >> a;
        sum += a;
    }
    long long X;
    cin >> X;
    long long cycles = X / sum, remaining = X % sum;
    int index = 0;
    while (remaining >= 0) {
        remaining -= A[index++];
    }
    cout << N * cycles + index << endl;
    return 0;
}