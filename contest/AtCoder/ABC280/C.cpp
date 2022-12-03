#include <iostream>
#include <string>

int main() {
    std::string s, t;
    std::cin >> s >> t;
    for (int i = 0; i < (int) t.size(); ++i) {
        if (i == (int) t.size()  - 1 || s[i] != t[i]) {
            std::cout << i + 1 << std::endl;
            break;
        }
    }
}