#include <iostream>
#include <numeric>
#include <vector>

int main() {
    int N;
    std::cin >> N;

    long long T;
    std::cin >> T;

    std::vector<int> A(N);
    for (int i = 0; i < N; ++i)
        std::cin >> A[i];

    T %= std::accumulate(A.begin(), A.end(), 0LL);

    int i = 0;
    while (T >= A[i]) 
        T -= A[i++];

    std::cout << i + 1 << " " << T << std::endl;
}