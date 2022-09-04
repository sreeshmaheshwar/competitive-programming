#include <bits/stdc++.h>
using namespace std;
const int FACE_SUM = 7;
const int NUM_ROLLS = 3;

int main() {
	int answer = FACE_SUM * NUM_ROLLS;
	for (int iter = 0; iter < NUM_ROLLS; ++iter) {
		int face_value;
		cin >> face_value;
		answer -= face_value;
	}
	cout << answer << endl;
	return 0;
}