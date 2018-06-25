#include <bits/stdc++.h>

using namespace std;

int n, k, dp[55][55];
long long a[55], s[55];

bool check(long long pattern) {
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= k; ++j) {
            if (!dp[i - 1][j - 1]) {
                continue;
            }

            for (int z = i; z <= n; ++z) {
                long long sum = s[z] - s[i - 1];

                if ((pattern | sum) == sum) {
                    dp[z][j] = 1;
                }
            }
        }
    }

    return dp[n][k];
}

int main() {
    cin >> n >> k;

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }

    long long ans = 0;

    for (int i = 60; i >= 0; --i) {
        if (check(ans | (1ll << i))) {
            ans |= (1ll << i);
        }
    }

    cout << ans;
}
