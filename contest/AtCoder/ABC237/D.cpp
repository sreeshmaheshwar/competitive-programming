#include <iostream>
#include <deque>
#include <string>

int main() {
	int n;
	std::cin >> n;
	std::string s;
	std::cin >> s;
	std::deque<int> A = {n};
	for (int i = n - 1; i >= 0; --i) {
		s[i] == 'R' ? A.push_front(i) : A.push_back(i);
    }
	for (auto a : A) {
		std::cout << a << " ";
    }
	return 0;
}