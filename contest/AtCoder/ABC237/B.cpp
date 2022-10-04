#include <iostream>
#include <vector>

int main() {
	int h, w;
	std::cin >> h >> w;
	std::vector<std::vector<int>> matrix(h, std::vector<int>(w));
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			std::cin >> matrix[i][j];
		}
	}
	for (int i = 0; i < w; ++i) {
		for (int j = 0; j < h; ++j) {
			std::cout << matrix[j][i] << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}