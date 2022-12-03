#include <iostream>

static constexpr int MOD = int(1e9) + 7;

struct mod_int {
  private:
    int val;

  public:
    mod_int() : val(0) {}
    mod_int(int _val) : val(_val) {}
    mod_int(long long _val) : val(_val % MOD) {}

    mod_int pow(long long exponent) const {
        mod_int ret = 1, base = *this;
        while (exponent) {
            if (exponent & 1) ret *= base;
            base *= base;
            exponent >>= 1;
        }
        return ret;
    }
    mod_int& operator+=(const mod_int& other) {
        val += other.val;
        if (val >= MOD) val -= MOD;
        return *this;
    }
    mod_int& operator-=(const mod_int& other) {
        val -= other.val;
        if (val < 0) val += MOD;
        return *this;
    }
    mod_int& operator*=(const mod_int& other) {
        val = 1LL * val * other.val % MOD;
        return *this;
    }
    mod_int& operator/=(const mod_int& other) {
        val = 1LL * val * other.pow(MOD - 2).val % MOD;
        return *this;
    }

    friend mod_int operator+(const mod_int& x, const mod_int& y) { return mod_int(x) += y; }
    friend mod_int operator-(const mod_int& x, const mod_int& y) { return mod_int(x) -= y; }
    friend mod_int operator*(const mod_int& x, const mod_int& y) { return mod_int(x) *= y; }
    friend mod_int operator/(const mod_int& x, const mod_int& y) { return mod_int(x) /= y; }
    friend std::ostream& operator<<(std::ostream& os, mod_int x) { return os << x.val; }
};

/*
Example use, solution to:
https://cses.fi/problemset/task/1079
*/

#include <vector>

std::vector<mod_int> factorial, inv_factorial;

void precompute_factorials(int maximum) {
    factorial.resize(maximum + 1);
    inv_factorial.resize(maximum + 1);
    for (int i = 0; i <= maximum; ++i) {
        factorial[i] = (i == 0 ? 1 : i * factorial[i - 1]);
        inv_factorial[i] = 1 / factorial[i];
    }
}

int main() {
    precompute_factorials(int(1e6));
    int n;
    std::cin >> n;
    for (int i = 0, a, b; i < n; ++i) {
        std::cin >> a >> b;
        std::cout << factorial[a] * inv_factorial[b] * inv_factorial[a - b] << std::endl;
    }
}