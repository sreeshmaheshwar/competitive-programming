#include <iostream>
#include <string>

int main() {
	long long n;
	std::cin >> n;
	std::string ans = "";
	while (n) {
		if (n % 2) {
			ans += 'A';
			n--;
		} else {
			ans += 'B';
			n /= 2;
		}
	}
	std::cout << std::string(ans.rbegin(), ans.rend());
	return 0;
}