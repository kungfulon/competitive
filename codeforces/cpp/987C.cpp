#include <bits/stdc++.h>

using namespace std;

int n, s[3005], c[3005];
long long f[5][3005];

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        cin >> s[i];
    }

    for (int i = 1; i <= n; ++i) {
        cin >> c[i];
        f[1][i] = c[i];
    }

    for (int k = 2; k <= 3; ++k) {
        for (int j = 1; j <= n; ++j) {
            f[k][j] = (1ll << 60);

            for (int i = 1; i < j; ++i) {
                if (s[i] >= s[j]) {
                    continue;
                }

                f[k][j] = min(f[k][j], f[k - 1][i] + c[j]);
            }
        }
    }

    long long ans = *min_element(f[3] + 1, f[3] + n + 1);
    cout << (ans == (1ll << 60) ? -1 : ans);
}
