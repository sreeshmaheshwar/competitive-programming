#include <bits/stdc++.h>
using namespace std;

const bool DEBUG_MODE = true;

bool is_case(string &s) {
    return s.substr(0, 4) == "Case";
}

void get_random_line() {
    string _;
    getline(cin, _);
}

vector<int> di = {1, -1, 0, 0};
vector<int> dj = {0, 0, 1, -1};

bool check(vector<string> &grid) {
    int n = grid.size();
    int m = grid[0].size();

    auto is_tree = [&](int i, int j) {
        return grid[i][j] == '^';
    };
    auto sad_tree = [&] (int i, int j) {
        int neighbour_count = 0;
        for (int k = 0; k < (int) di.size(); ++k) {
            int neighbour_i = i + di[k];
            int neighbour_j = j + dj[k];
            if (0 <= neighbour_i && neighbour_i < n && 0 <= neighbour_j && neighbour_j < m && is_tree(neighbour_i, neighbour_j)) {
                neighbour_count++;
            }
        }
        if (DEBUG_MODE && neighbour_count == 4) {
            cerr << neighbour_count << endl;
        }
        assert(neighbour_count <= 4);
        return neighbour_count < 2;
    };

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (is_tree(i, j) && sad_tree(i, j)) {
                return false;
            }
        }
    }
    return true;
}   

int main() {
    vector<vector<string>> inputs;
    get_random_line(); // discard first line of submission output
    bool end_of_file = false;
    while (!end_of_file) {
        string s;
        getline(cin, s);
        vector<string> grid;
        while (!is_case(s) && !end_of_file) {
            grid.push_back(s);
            if (!getline(cin, s)) end_of_file = true;
        }
        if (!grid.empty()) {
            inputs.push_back(grid);
        }
    }
    for (auto &grid : inputs) {
        assert(check(grid));
    }
    cout << "All tests passed!" << endl;
    return 0;  
}