#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
	int N;
	std::cin >> N;
	std::string S;
	std::cin >> S;
	std::vector<int> pref(N + 1);
	for (int i = 0; i < N; ++i) 
		pref[i + 1] = pref[i] + (S[i] == 'W');
	std::vector<int> suff(N + 1);
	for (int i = N - 1; i >= 0; --i)
		suff[i] = suff[i + 1] + (S[i] == 'E');
	int ans = N;
	for (int i = 0; i < N; ++i) 
		ans = std::min(ans, pref[i] + suff[i + 1]);
	std::cout << ans;
	return 0;
}