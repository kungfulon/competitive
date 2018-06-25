#include <bits/stdc++.h>

using namespace std;

int n, a[5005], d[5005], f[5005][5005], mx[5005][5005];

void calc(int i, int c) {
    if (c == 1) {
        f[i][i] = mx[i][i] = a[i];
        return;
    }

    if (!d[c - 1]) {
        d[c - 1] = 1;

        for (int j = 1; j <= n - c + 2; ++j) {
            calc(j, c - 1);
        }
    }

    f[i + c - 1][i] = f[i + c - 2][i] ^ f[i + c - 1][i + 1];
    mx[i + c - 1][i] = max(f[i + c - 1][i], max(mx[i + c - 2][i], mx[i + c - 1][i + 1]));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    calc(1, n);

    int q;
    cin >> q;
    
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << mx[r][l] << '\n';
    }
}
