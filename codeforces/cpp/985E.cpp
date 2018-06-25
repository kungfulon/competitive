#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int n, k, d;
    cin >> n >> k >> d;
    vector<int> a(n), f(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    if (a[k - 1] - a[0] > d) {
        cout << "NO";
        return 0;
    }

    int l = 0;

    for (int i = 0; i < k; ++i) {
        f[i] = i + 1;
    }
    
    for (int r = k; r < n; ++r) {
        if (a[r] - a[l] > d) {
            while ((a[r] - a[l] > d || f[l - 1] < k) && l < r) {
                ++l;
            }
        }
        
        f[r] = r - l + 1;
    }

    int u = n - 1;
    
    while (u > 0) {
        if (f[u] < k) {
            cout << "NO";
            return 0;
        }

        u -= f[u];
    }

    cout << "YES";
}
