#include <bits/stdc++.h>
using namespace std;

int main() {
    long long X, A, D, N;
    cin >> X >> A >> D >> N;
    auto get_val = [&](long long index) -> long long {
        return A + index * D; 
    };
    auto dist = [&](long long index) -> long long {
        return abs(get_val(min(N - 1, max(0LL, index))) - X);
    };
    long long L = 0, R = N - 1, answer = D > 0 ? N : 0; 
    while (L <= R) {
        long long mid = (L + R) / 2;
        if (get_val(mid) > X) {
            answer = mid;
            D > 0 ? R = mid - 1 : L = mid + 1;
        } else {
            D < 0 ? R = mid - 1 : L = mid + 1;
        }
    }
    cout << min({dist(answer - 1), dist(answer), dist(answer + 1)}) << endl;
    return 0;
}