#include <iostream>

int main() {
	int x, y;
	char dot;
	std::cin >> x >> dot >> y;
	std::cout << x;
	if (y <= 2) {
		std::cout << '-';
	} else if (y >= 7) {
		std::cout << '+';
	}
	return 0;
}