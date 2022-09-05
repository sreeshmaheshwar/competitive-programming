#include <algorithm>
#include <iostream>
#include <vector>
const int INF = 1e9 + 5;

int main() {
	int N;
	std::cin >> N;
	std::vector<int> A(N);
	long long abs_sum = 0;
	int abs_min = INF;
	for (int i = 0; i < N; ++i) {
		std::cin >> A[i];
		abs_sum += abs(A[i]);
		abs_min = std::min(abs_min, abs(A[i]));
	}
	for (int i = 0; i < N - 1; ++i) {
		if (A[i] < 0) {
			A[i + 1] *= -1;
		}
	}
    std::cout << abs_sum - (A.back() < 0 ? abs_min * 2 : 0) << std::endl;
	return 0;
}