#include <bits/stdc++.h>

using namespace std;

template<int mod>
class modint {
public:
    int value;

    modint(long long x = 0) {
        value = normalize(x);
    }

    int normalize(long long x) {
        if (x < -mod || x >= mod)
            x %= mod;
        if (x < 0) x += mod;
        return static_cast<int>(x);
    }

    explicit operator int() const { return value; }

    modint operator-() const { return modint(-value); }

    modint &operator+=(modint rhs) {
        if ((value += rhs.value) >= mod) value -= mod;
        return *this;
    }

    modint &operator-=(modint rhs) {
        if ((value -= rhs.value) < 0) value += mod;
        return *this;
    }

    modint &operator*=(modint rhs) {
        value = normalize(static_cast<long long>(value) * rhs.value % mod);
        return *this;
    }

    modint &operator/=(modint rhs) { return *this *= modint(inverse(rhs.value, mod)); }

    int inverse(int a, int m) {
        int u = 0, v = 1;
        while (a != 0) {
            int t = m / a;
            m -= t * a;
            swap(a, m);
            u -= t * v;
            swap(u, v);
        }
        assert(m == 1);
        return u;
    }

    friend modint operator+(modint lhs, modint rhs) { return lhs += rhs; }

    friend modint operator-(modint lhs, modint rhs) { return lhs -= rhs; }

    friend modint operator*(modint lhs, const modint rhs) { return lhs *= rhs; }

    friend modint operator/(modint lhs, const modint rhs) { return lhs /= rhs; }
};

constexpr int mod = (int) 1e9 + 7;
using mint = modint<mod>;

// usage example
int _main() {
    mint a = 1;
    mint b = 1;
    b += 1;
    mint c = 1000'000'000;
    mint d = a / b * c / c;
    cout << ((int) d) << endl;
}
