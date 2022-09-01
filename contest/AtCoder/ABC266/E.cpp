/* 
Explanation:

If I get a roll of d, and I have i turns left, I should
play again if my expected result after doing so (say, E)
is greater than d and end the game with my answer of d 
otherwise.

Thus, if we iterate in order of i and compute the desired
expected value for each iteration, then the value of E
above is simply the expectation computed in the previous
iteration (bottom-up, iterative dynamic programming).

If I have i turns left (and have gotten a roll of d)
and choose to play on, the expected value of my score will be E, 
and otherwise it will be d. Each roll has a probability of
1/6 of occuring, so it suffices to iterate over d (although
we can be smarter and avoid said iteration by counting the number
of rolls < E in constant time - this is unnecessary given the 
problem constraints, however)
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    double E = 3.5;
    for (int i = 1; i < N; ++i) {
        double curE = 0;
        for (int d = 1; d <= 6; ++d) {
            curE += (1 / 6.0) * max<double>(d, E);
        }
        E = curE;
    }
    cout << fixed << setprecision(12) << E << endl;
    return 0;
}