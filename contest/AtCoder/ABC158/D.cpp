#include <iostream>
#include <deque>
#include <string>

int main() {
	std::string s;
	std::cin >> s;
	std::deque<char> dq(s.begin(), s.end());
	int q;
	std::cin >> q;
    bool is_reversed = false;
	while (q--) {
		int t;
		std::cin >> t;
		if (t == 1) {
			is_reversed ^= 1;
		} else {
			int f;
			std::cin >> f;
			char c;
			std::cin >> c;
			(--f) ^= is_reversed;
			f ? dq.push_back(c) : dq.push_front(c);
		}
	}
	std::cout << (is_reversed ? std::string(dq.rbegin(), dq.rend()) : std::string(dq.begin(), dq.end()));
	return 0;
}