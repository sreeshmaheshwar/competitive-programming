#include <iostream>
#include <string>

const size_t VALID_LENGTH = 8;

inline bool is_upper(char c) { return 'A' <= c && c <= 'Z'; }

int main() {
    std::string s;
    std::cin >> s;

    bool is_valid = true;
    if (s.size() == VALID_LENGTH) {
        /* Both starting and ending characters must be upper case. */
        is_valid &= is_upper(s[0]) && is_upper(s[VALID_LENGTH - 1]);
        /* The second character must be a digit and non-zero. */
        is_valid &= !is_upper(s[1]) && s[1] > '0';
        /* All other characters must be digits. */
        for (int i = 2; i < int(VALID_LENGTH) - 1; ++i) is_valid &= !is_upper(s[i]);
    } else {
        is_valid = false;
    }

    std::cout << (is_valid ? "Yes" : "No") << std::endl;
}