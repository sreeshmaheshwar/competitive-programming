#include <algorithm>
#include <iostream>
#include <vector>

int main() {
	int N;
	std::cin >> N;
	std::vector<int> A(N);
	long long abs_sum = 0;
	int abs_min = 1e9;
	bool has_zero = false;
	for (int i = 0; i < N; ++i) {
		std::cin >> A[i];
		abs_sum += abs(A[i]);
		abs_min = std::min(abs_min, abs(A[i]));
		has_zero |= !A[i];
	}
	for (int i = 0; i < N - 1; ++i) { // push negative to end
		if (A[i] < 0) {
			A[i + 1] *= -1;
		}
	}
	if (A.back() > 0 || has_zero) { // can get rid of negative
		std::cout << abs_sum << std::endl;
	} else { // push negative to least value
		std::cout << abs_sum - 2 * abs_min << std::endl;
	}
	return 0;
}