#include <iostream>
#include <string>

int main() {
    int h, w, answer = 0;
    std::cin >> h >> w;
    while (h--) {
        std::string s;
        std::cin >> s;
        for (char c : s) 
            answer += c == '#';
    }
    std::cout << answer;
}