#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

const int ALPHA = 26;
const char MIN_CHAR = 'a';

int main() {
	int N;
	std::cin >> N;
	std::string S;
	std::cin >> S;
	
	std::vector<int> x_freq(ALPHA), y_freq(ALPHA); 
	for (char c : S) 
		x_freq[c - MIN_CHAR]++;

	int ans = 0;
	for (char c : S) {
		x_freq[c - MIN_CHAR]--;
		y_freq[c - MIN_CHAR]++;
		int num_diff = 0;
		for (int i = 0; i < ALPHA; ++i) 
			num_diff += x_freq[i] && y_freq[i];
		ans = std::max(ans, num_diff);
	}
	std::cout << ans;
	return 0;
}