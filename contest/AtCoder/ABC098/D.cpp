#include <iostream>
#include <vector>

int main() {
	int N;
	std::cin >> N;
	std::vector<int> A(N);
	for (int& a : A) 
        std::cin >> a;
	long long sum = 0, answer = 0;
	for (int i = 0, j = 0; i < N; ++i) {
		while (j < N && sum + A[j] == (sum ^ A[j])) sum += A[j++];
		answer += j - i;
		sum -= A[i];
	}
	std::cout << answer;
	return 0;
}