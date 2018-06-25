#include <bits/stdc++.h>

using namespace std;

char ans[1005][1005];

int main() {
    ios_base::sync_with_stdio(0);
    int n, a, b;
    cin >> n >> a >> b;

    if ((a != 1 && b != 1) || (n < 4 && n > 1 && a == 1 && b == 1)) {
        cout << "NO";
        return 0;
    }

    cout << "YES\n";

    if (a == 1) {
        memset(ans, '1', sizeof(ans));

        for (int i = 0; i < n; ++i) {
            ans[i][i] = '0';
        }

        if (b == 1 && n % 2 != 0) {
            ans[0][n - 1] = ans[n - 1][0] = '0';
        }

        for (int i = 1; i <= (n - b); ++i) {
            ans[i][i - 1] = ans[i - 1][i] = '0';
        }
    } else {
        memset(ans, '0', sizeof(ans));

        for (int i = 1; i <= (n - a); ++i) {
            ans[i][i - 1] = ans[i - 1][i] = '1';
        }
    }

    for (int i = 0; i < n; ++i) {
        ans[i][n] = 0;
        cout << ans[i] << '\n';
    }
}
