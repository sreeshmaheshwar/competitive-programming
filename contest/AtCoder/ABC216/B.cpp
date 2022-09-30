#include <iostream>
#include <set>
#include <utility>

int main() {
	int n;
	std::cin >> n;
	std::set<std::pair<std::string, std::string>> names;
	for (int i = 0; i < n; ++i) {
		std::string s, t;
		std::cin >> s >> t;
		names.emplace(s, t);
	}
	std::cout << (int(names.size()) < n ? "Yes" : "No");
	return 0;
}