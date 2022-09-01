/*
Explanation:

Let most_caught[i][j] be the maximal Snuke size caught
at time i where j is Takahashi's current coordinate.
From here, Takahashi can move to (j - 1), j or (j + 1)
to get to a new time of (i + 1). If there so happens
to be a Snuke at this location and at this time, then
he may catch that Snuke, and his score will increase
accordingly. Thus, we have our dynamic programming
transitions. 

Our answer is the maximum of most_caught[T[n - 1]][j],
over all j, since after moment in time no more Snuke 
can be captured. Alternatively, we can simply use
the maximum value of T_i given in the problem's constraints.

We also notice that we need not store the first
dimension (the time, i) in our DP state, as we simply require the
previous state (the previous second) to compute the current one.
*/

#include <bits/stdc++.h>
using namespace std;
const int TOTAL_TIME = 1e5;
const int COORDINATES = 5;
const vector<int> DIR = {+1, 0, -1};

int main() {
    int N;
    cin >> N;
    map<pair<int, int>, int> snuke_size;
    for (int i = 0; i < N; ++i) {
        int T, X, A;
        cin >> T >> X >> A;
        snuke_size[{T, X}] = A;
    }
    vector<long long> most_caught(COORDINATES, -1);
    most_caught[0] = 0;
    for (int t = 0; t < TOTAL_TIME; ++t) {
        vector<long long> new_most_caught(COORDINATES, -1);
        for (int i = 0; i < COORDINATES; ++i) {
            if (most_caught[i] == -1) { // it is not possible to be at this coordinate
                continue;
            }
            for (int d : DIR) { // DP transition is coordinate i -> coordinate i + d
                if (0 <= i + d && i + d < COORDINATES) {
                    new_most_caught[i + d] = max(new_most_caught[i + d], most_caught[i] + snuke_size[{t + 1, i + d}]);
                }
            }
        }
        most_caught.swap(new_most_caught);
    }
    cout << *max_element(most_caught.begin(), most_caught.end()) << endl;
    return 0;
}