#include <algorithm>
#include <iostream>
#include <vector>

int main() {
	int N;
	std::cin >> N;
	std::vector<int> V(N);
	for (int i = 0; i < N; ++i) {
        std::cin >> V[i];
    }
    int answer = 0;
    for (int i = 0; i < N; ++i) {
        int C;
        std::cin >> C;
        answer += std::max(0, V[i] - C);
    }
    std::cout << answer << std::endl;
	return 0;
}