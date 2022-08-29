#include <bits/stdc++.h>
using namespace std;

const char TREE = '^';
const char EMPTY = '.';

const int DIRECTIONS = 4;
vector<int> di = {+1, -1, 0, 0};
vector<int> dj = {0, 0, +1, -1};

int R, C;
vector<string> grid;

bool is_valid_cell(int i, int j) {
    return 0 <= i && i < R && 0 <= j && j < C;
}

bool is_sad_tree(int i, int j) {
    if (grid[i][j] != TREE) {
        return false;
    }
    int neighbour_count = 0;
    for (int direction = 0; direction < DIRECTIONS; ++direction) {
        int ni = i + di[direction], nj = j + dj[direction];
        if (is_valid_cell(ni, nj)) {
            neighbour_count += grid[ni][nj] == TREE;
        }
    }
    return neighbour_count < 2;
}

void remove_sad_trees(int i, int j) {
    if (grid[i][j] == TREE) {
        grid[i][j] = EMPTY;
        for (int direction = 0; direction < DIRECTIONS; ++direction) {
            int ni = i + di[direction], nj = j + dj[direction];
            if (is_valid_cell(ni, nj) && is_sad_tree(ni, nj)) {
                remove_sad_trees(ni, nj);
            }
        }
    }
}

void solve() {
    cin >> R >> C;
    vector<string> orginal_grid(R);
    grid = vector<string>(R);
    for (int i = 0; i < R; ++i) {
        cin >> orginal_grid[i];
        for (int j = 0; j < C; ++j) {
            if (orginal_grid[i][j] == EMPTY) {
                grid[i] += TREE;
            } else {
                grid[i] += orginal_grid[i][j];
            }
        }
    }
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            if (is_sad_tree(i, j)) {
                remove_sad_trees(i, j);
            }
        }
    }
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            if (orginal_grid[i][j] == TREE && grid[i][j] != TREE) {
                cout << "Impossible\n";
                return;
            }
        }
    }
    cout << "Possible\n";
    for (int i = 0; i < R; ++i) {
        cout << grid[i] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for (int test_case = 1; test_case <= T; ++test_case) {
        cout << "Case #" << test_case << ": ";
        solve();
    }
    return 0;
}