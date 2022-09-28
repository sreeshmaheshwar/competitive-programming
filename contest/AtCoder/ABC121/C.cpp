#include <iostream>
#include <algorithm>
#include <vector>

struct drink {
	int a, b;

	bool operator<(const drink& other) const {
		return a < other.a;
	}
};

int main() {
	int n, m;
	std::cin >> n >> m;
	std::vector<drink> drinks(n);
	for (auto& [a, b] : drinks) 
		std::cin >> a >> b;

	std::sort(drinks.begin(), drinks.end());

	long long answer = 0;
	for (int i = 0; i < n && m > 0; ++i) {
		answer += (long long) drinks[i].a * std::min(drinks[i].b, m);
		m -= drinks[i].b;
	}
	std::cout << answer;
	return 0;
}