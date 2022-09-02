#include <bits/stdc++.h>
using namespace std;

int main() {
	long long n;
	cin >> n;
	long long answer = 0;
	if (n % 2 == 0) {
		for (long long five_power = 5; five_power <= n; five_power *= 5) {
			answer += n / (five_power * 2);
		}
	}
	cout << answer << endl;
	return 0;
}