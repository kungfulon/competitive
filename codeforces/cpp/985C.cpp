#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k, l, m;
    cin >> n >> k >> l;
    m = n * k;
    vector<int> a(m), steps(k + 1);

    for (int i = 0; i < m; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    int count = upper_bound(a.begin(), a.end(), a[0] + l) - a.begin();

    if (count < n) {
        cout << 0;
        return 0;
    }

    steps[1] = n;
    int len = n, step = k;

    while (len < count) {
        while (count - len >= (step - 1)) {
            ++steps[step];
            --steps[1];
            len += step - 1;
        }

        --step;
    }

    long long ans = 0;

    for (int i = k, j = 0; i > 0; --i) {
        for (; steps[i]--; j += i) {
            ans += a[j];
        }
    }

    cout << ans;
}
