#include <iostream>

static constexpr int MOD = 998244353;

struct mod_int {
  private:
    int val;

  public:
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

    mod_int operator+(const mod_int& other) const { return mod_int(*this) += other; }
    mod_int operator-(const mod_int& other) const { return mod_int(*this) -= other; }
    mod_int operator*(const mod_int& other) const { return mod_int(*this) *= other; }
    mod_int operator/(const mod_int& other) const { return mod_int(*this) /= other; }
    friend std::ostream& operator<<(std::ostream& os, mod_int x) { return os << x.val; }
};

/* 
Example main program,
solution to: https://atcoder.jp/contests/abc238/tasks/abc238_c
*/

int main() {
    long long n;
    std::cin >> n;

    auto sum = [](mod_int n) -> mod_int { return n * (n + 1) / 2; };

    mod_int ans = 0;
    for (long long i = 1; i <= n; i *= 10)
        ans += sum(std::min(n + 1, i * 10) - i);

    std::cout << ans << std::endl;
}