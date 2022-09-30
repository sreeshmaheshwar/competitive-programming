#include <algorithm>
#include <iostream>
#include <vector>

int main() {
	int n, k;
	std::cin >> n >> k;
	std::vector<int> a(n);
	for (int& x : a) 
		std::cin >> x;
	int L = 0, R = *std::max_element(a.begin(), a.end());
	while (L < R) {
		int mid = L + (R - L) / 2;
		long long num_rides = 0;
		for (int x : a) num_rides += std::max(0, x - mid);
		num_rides <= k ? R = mid : L = mid + 1;
	}
	long long answer = 0;
	for (int x : a) {
		k -= std::max(0, x - L);
		answer += std::max(0LL, (long long)x*(x+1)/2-(long long)L*(L+1)/2);
	}
	std::cout << answer + (long long) k * L;
	return 0;
}