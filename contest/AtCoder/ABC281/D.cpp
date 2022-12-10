#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int N, K, D;
    std::cin >> N >> K >> D;
    std::vector<std::vector<long long>> max_sum(N + 1, std::vector<long long>(D, -1));
    max_sum[0][0] = 0;
    for (int i = 0, a; i < N; ++i) {
        std::cin >> a;
        auto new_max_sum = max_sum;

        for (int j = 0; j < N; ++j) 
            for (int k = 0; k < D; ++k) 
                if (max_sum[j][k] >= 0)
                    new_max_sum[j+1][(k+a)%D] = std::max(new_max_sum[j+1][(k+a)%D], max_sum[j][k]+a);

        max_sum = new_max_sum; 
    }
    std::cout << max_sum[K][0] << std::endl;
}