#include <iostream>
#include <set>
#include <string>
#include <vector>

int main() {
	std::string s, t;
	std::cin >> s >> t;
	std::vector<std::set<int>> dest(26), orig(26);
	for (int i = 0; i < (int) s.size(); ++i) {
		dest[s[i] - 'a'].insert(t[i] - 'a');
		orig[t[i] - 'a'].insert(s[i] - 'a');
	}
	for (int i = 0; i < 26; ++i) {
		if (dest[i].size() > 1 || orig[i].size() > 1) {
			std::cout << "No" << std::endl;
			return 0;
		}
	}
	std::cout << "Yes" << std::endl;
	return 0;
}