#include <bits/stdc++.h>
using namespace std;

bool on(int mask, int i) {
	return mask >> i & 1;
}

void solve() {
	int N, M, K;
	cin >> N >> M >> K;
	vector<long long> L(N), R(N), A(N);
	for (int i = 0; i < N; ++i) {
		cin >> L[i] >> R[i] >> A[i];
	}
	vector<vector<int>> adj(N);
	for (int i = 0; i < M; ++i) {
		int u, v; 
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<long long> mask_sum(1 << N);
	vector<int> masks(1 << N);
	iota(masks.begin(), masks.end(), 0);
	for (int i = 0; i < (1 << N); ++i) {
		for (int j = 0; j < N; ++j) {
			if (on(i, j)) {
				mask_sum[i] += A[j];
			}
		}
	}
	sort(masks.begin(), masks.end(), [&](const int &m1, const int &m2) {
		return mask_sum[m1] < mask_sum[m2];
	});
	vector<long long> dp(1 << N, 0);
	for (int i = 0; i < N; ++i) {
		dp[1 << i] = 1;
	}
	long long answer = 0;
	for (int mask : masks) {
		if (mask_sum[mask] == K) {
			answer += dp[mask];
		}
		vector<bool> seen(N, false);
		for (int i = 0; i < N; ++i) {
			if (on(mask, i)) {
				for (int j : adj[i]) {
					if (L[j] <= mask_sum[mask] && mask_sum[mask] <= R[j] && !seen[j] && !on(mask, j)) {
						dp[mask | (1 << j)] += dp[mask];
						seen[j] = true;
					}
				}
			}
		}
	}
	cout << answer << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; ++test_case) {
		cout << "Case #" << test_case << ": ";
		solve();
	}
	return 0;
}