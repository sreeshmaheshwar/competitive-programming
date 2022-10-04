#include <iostream>

int main() {
	int64_t n;
	std::cin >> n;
	std::cout << (1LL << 31 >= -n && +n < (1LL << 31) ? "Yes" : "No");
	return 0;
}