#include <algorithm>
#include <iostream>

int main() {
	long long N, A, B;
	std::cin >> N >> A >> B;
	std::cout << A * (N / (A + B)) + std::min(N % (A + B), A);
    return 0;
}