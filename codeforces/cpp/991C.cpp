#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    long long n;
    cin >> n;
    long long l = 0, r = n;

    while (l < r - 1) {
        long long k = (l + r) >> 1, m = n, tot = 0;

        while (m > 0) {
            tot += min(m, k);
            m -= min(m, k);
            m -= m / 10;
        }

        if (tot >= (n + 1) / 2) {
            r = k;
        } else {
            l = k;
        }
    }

    cout << r;
}
