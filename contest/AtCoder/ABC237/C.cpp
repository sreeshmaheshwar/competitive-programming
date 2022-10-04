#include <deque>
#include <iostream>
#include <string>

const char TARGET_CHAR = 'a';

int main() {
	std::string s;
	std::cin >> s;
	std::deque<char> dq(s.begin(), s.end());
	while (dq.size() >= 2 && dq.front() == TARGET_CHAR && dq.back() == TARGET_CHAR) {
		dq.pop_front();
		dq.pop_back();
	}
	while (!dq.empty() && dq.back() == TARGET_CHAR) {
		dq.pop_back();
	}
	std::cout << (dq == std::deque<char>(dq.rbegin(), dq.rend()) ? "Yes" : "No");
	return 0;
}