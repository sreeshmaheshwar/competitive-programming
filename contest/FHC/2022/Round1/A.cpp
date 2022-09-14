#include <bits/stdc++.h>
using namespace std;

vector<int> z_algorithm(vector<int> s) {
    int n = s.size();
	vector<int> z(n);
    for (int i = 1, j = 0; i < n; i++) {
    	if (j + z[j] > i) z[i] = min(j + z[j] - i, z[i - j]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
        if (j + z[j] < i + z[i]) j = i;
    }
    z.front() = n;
    return z;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    vector<int> b(n);
    for (int i = 0; i < n; ++i)
        cin >> b[i];

    bool possible;
    if (n == 2 || k == 0) {
        if (n == 2 && k % 2 == 1)
        	swap(a[0], a[1]);
        possible = a == b;
    } else {
    	possible = false;
    	vector<int> search_string = b;
    	search_string.push_back(-1);
    	for (int iter = 0; iter < 2; ++iter)
    		search_string.insert(search_string.end(), a.begin(), a.end());

    	auto z = z_algorithm(search_string);
    	for (int i = n + 1; i < (int) z.size(); ++i)
            if (z[i] == n && (k > 1 || i % n != 1))
            	possible = true;
    }
    cout << (possible ? "YES" : "NO") << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int test_case = 1; test_case <= T; ++test_case) {
        cout << "Case #" << test_case << ": ";
        solve();
    }
    
    return 0;
}