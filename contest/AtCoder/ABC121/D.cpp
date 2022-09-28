#include <iostream>

long long pref_xor(long long n) {
	if (n % 4 == 0) return n;
	if (n % 4 == 1) return 1;
	if (n % 4 == 2) return n + 1;
	return 0;
}

int main() {
	long long a, b;
	std::cin >> a >> b;
	std::cout << (pref_xor(b) ^ pref_xor(a - 1));
	return 0;
}