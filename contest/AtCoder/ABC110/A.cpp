#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int panel_sum = 0, max_panel = 0;
    for (int i = 0; i < 3; ++i) {
        int panel;
        std::cin >> panel;
        panel_sum += panel;
        max_panel = std::max(max_panel, panel);
    }
    std::cout << (max_panel * 10 + panel_sum - max_panel) << std::endl;
    return 0;
}