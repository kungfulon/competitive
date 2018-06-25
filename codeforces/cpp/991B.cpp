#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> a(n);
    double mean = 0.0;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        mean += a[i];
    }

    mean /= (double)n;

    if ((int)round(mean) == 5) {
        cout << 0;
        return 0;
    }

    sort(a.begin(), a.end());
    int ans = 0;

    for (int i = 0; i < n; ++i) {
        a[i] = 5;
        ++ans;
        mean = 0.0;

        for (int j = 0; j < n; ++j) {
            mean += a[j];
        }

        mean /= (double)n;

        if ((int)round(mean) == 5) {
            cout << ans;
            break;
        }
    }
}
