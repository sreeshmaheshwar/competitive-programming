#include <iostream>
#include <vector>

int main() {
	int N, M, C;
	std::cin >> N >> M >> C;
	std::vector<int> B(M);
	for (int& b : B) 
		std::cin >> b;
	int answer = 0;
	while (N--) {
		int sum = C;
		for (int i = 0, a; i < M; ++i) {
			std::cin >> a;
			sum += a * B[i];
		}
		answer += sum > 0;
	}
	std::cout << answer;
	return 0;
}