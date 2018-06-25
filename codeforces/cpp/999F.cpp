#include <bits/stdc++.h>

using namespace std;

int n, k, h[15], f[505][505 * 15], fav[505], cf[100005], cc[100005];

// cf[t] guys, total cc[t] cards of type t
int calc(int t) {
    memset(f, 0, sizeof(f));

    for (int i = 1; i <= cf[t]; ++i) {
        for (int j = 1; j <= cc[t]; ++j) {
            for (int z = 0; z <= min(j, k); ++z) {
                f[i][j] = max(f[i][j], f[i - 1][j - z] + h[z]);
            }
        }
    }

    return f[cf[t]][cc[t]];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> k;

    for (int i = 0; i < n * k; ++i) {
        int x;
        cin >> x;
        ++cc[x];
    }

    for (int i = 1; i <= n; ++i) {
        cin >> fav[i];
        ++cf[fav[i]];
    }

    for (int i = 1; i <= k; ++i) {
        cin >> h[i];
    }

    int ans = 0;

    for (int i = 1; i <= 100005; ++i) {
        if (cf[i] == 0) {
            continue;
        }

        ans += calc(i);
    }

    cout << ans;
}
