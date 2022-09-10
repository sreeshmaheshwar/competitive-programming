#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K, Q;
    cin >> N >> K >> Q;
    vector<int> A(K);
    for (int i = 0; i < K; ++i) {
        cin >> A[i];
    }
    while (Q--) {
        int L;
        cin >> L; 
        L--;
        if (A[L] != N && (L == K - 1 || A[L + 1] != A[L] + 1)) A[L]++;
    }
    for (int i = 0; i < K; ++i) {
        cout << A[i] << " ";
    }
    return 0;
}