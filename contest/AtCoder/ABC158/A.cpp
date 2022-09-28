#include <iostream>
#include <string>

int main() {
	std::string S;
	std::cin >> S;
	std::cout << (S == std::string(S.size(), S[0]) ? "No" : "Yes");
    return 0;
}