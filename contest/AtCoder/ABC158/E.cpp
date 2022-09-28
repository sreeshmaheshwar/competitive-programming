#include <iostream>
#include <string>
#include <vector>

int main() {
	int n, p;
	std::cin >> n >> p;
	std::string s;
	std::cin >> s;
	long long ans = 0;
    if (p == 2 || p == 5) {
        for (int i = 0; i < n; ++i)
            if (int(s[i] - '0') % p == 0)
                ans += i + 1;
    } else {
		std::vector<int> suff_cnt(p + 1);
		suff_cnt[0]++;
        int ten_pow = 1, cur_mod = 0;
        for (int i = n - 1; i >= 0; --i) {
			cur_mod = (ten_pow * (s[i] - '0') + cur_mod) % p;
			ten_pow = (ten_pow * 10) % p;
			ans += suff_cnt[cur_mod]++;
		}
	}
    std::cout << ans << std::endl;
	return 0;
}