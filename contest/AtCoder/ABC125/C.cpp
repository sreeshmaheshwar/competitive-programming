#include <algorithm>
#include <iostream>
#include <vector>

int main() {
	int N;
	std::cin >> N;
	std::vector<int> A(N);
	std::vector<int> pref_gcd(N + 1);
	pref_gcd[0] = 0;
	for (int i = 0; i < N; ++i) {
		std::cin >> A[i];
		pref_gcd[i + 1] = std::__gcd(pref_gcd[i], A[i]);
	}
	std::vector<int> suff_gcd(N + 1);
	suff_gcd[N] = 0;
	for (int i = N - 1; i >= 0; --i) {
		suff_gcd[i] = std::__gcd(suff_gcd[i + 1], A[i]);
	}
	int ans = 0;
	for (int i = 0; i < N; ++i) {
		ans = std::max(ans, std::__gcd(pref_gcd[i], suff_gcd[i + 1]));
	}
	std::cout << ans << std::endl;
	return 0;
}