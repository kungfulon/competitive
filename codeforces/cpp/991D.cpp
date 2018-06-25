#include <bits/stdc++.h>

using namespace std;

int n, f[105][5];

int main() {
    ios_base::sync_with_stdio(0);
    string s[2];
    cin >> s[0];
    cin >> s[1];
    n = s[0].size();

    for (int i = 2; i <= n; ++i) {
        f[i][0] = max(*max_element(f[i - 1], f[i - 1] + 5), *max_element(f[i - 2], f[i - 2] + 5));

        // xx
        // x.
        if (s[0][i - 2] == '0' && s[0][i - 1] == '0' && s[1][i - 2] == '0') {
            f[i][1] = f[i - 1][0] + 1;
        }

        // xx
        // .x
        if (s[0][i - 2] == '0' && s[0][i - 1] == '0' && s[1][i - 1] == '0') {
            f[i][2] = max(f[i - 1][0], f[i - 1][4]) + 1;
        }

        // .x
        // xx
        if (s[0][i - 1] == '0' && s[1][i - 2] == '0' && s[1][i - 1] == '0') {
            f[i][3] = max(f[i - 1][0], f[i - 1][1]) + 1;
        }

        // x.
        // xx
        if (s[0][i - 2] == '0' && s[1][i - 2] == '0' && s[1][i - 1] == '0') {
            f[i][4] = f[i - 1][0] + 1;
        }
    }

    int ans = 0;

    for (int i = 1; i <= n; ++i) {
        ans = max(ans, *max_element(f[i], f[i] + 5));
    }

    cout << ans;
}
