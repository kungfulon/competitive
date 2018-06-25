#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int a, b, c, n;
    cin >> a >> b >> c >> n;
    a -= c;
    b -= c;

    if (a < 0 || b < 0) {
        cout << -1;
        return 0;
    }

    n -= (a + b + c);

    if (n < 1) {
        cout << -1;
        return 0;
    }

    cout << n;
}
