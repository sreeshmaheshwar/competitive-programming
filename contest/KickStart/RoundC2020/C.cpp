#include <bits/stdc++.h>
using namespace std;
const int OFFSET = 1e7;
int prefix_sum_count[2 * OFFSET + 1];

void increment(int prefix_sum) {
    prefix_sum_count[prefix_sum + OFFSET]++;
}

int get_count(int prefix_sum) {
    return prefix_sum + OFFSET >= 0 ? prefix_sum_count[prefix_sum + OFFSET] : 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for (int test_case = 1; test_case <= T; ++test_case) {
        memset(prefix_sum_count, 0, sizeof(prefix_sum_count));
        int N;
        cin >> N;
        long long answer = 0, prefix_sum = 0;
        increment(prefix_sum);
        for (int j = 0; j < N; ++j) {
            int a;
            cin >> a;
            prefix_sum += a;
            for (int i = 0; i * i <= OFFSET; ++i)
                answer += get_count(prefix_sum - i * i);
            increment(prefix_sum);
        }
        cout << "Case #" << test_case << ": " << answer << '\n';
    }
    return 0;
}