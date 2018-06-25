#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

long long powM(long long x, long long y) {
    if (y == 0) {
        return 1;
    }

    long long res = powM(x, y >> 1);
    res = (res * res) % MOD;

    if (y & 1) {
        res = (res * x) % MOD;
    }

    return res;
}

long long modInverse(long long a, long long m)
{
    long long m0 = m;
    long long y = 0, x = 1;
 
    if (m == 1) {
      return 0;
    }
 
    while (a > 1) {
        long long q = a / m;
        long long t = m;
 
        m = a % m, a = t;
        t = y;
        y = x - q * y;
        x = t;
    }
 
    if (x < 0) {
       x += m0;
    }
 
    return x;
}

int main() {
    ios_base::sync_with_stdio(0);
    long long x, k;
    cin >> x >> k;

    if (x == 0) {
        cout << 0;
        return 0;
    }

    x %= MOD;
    long long xd = powM(2, k);
    long long p = modInverse(xd, MOD);
    xd = ((((xd * xd) % MOD) * x) % MOD) - ((xd * (xd - 1) / 2) % MOD);

    if (xd < 0) {
        xd += MOD;
    }

    xd = (xd * 2) % MOD;
    xd = (xd * p) % MOD;
    cout << xd;
}
