#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k, ans;
    cin >> n >> k;
    ans = n;
    vector<int> a(n), cnt(3000005);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ++cnt[a[i]];
    }

    sort(a.begin(), a.end());
    a.resize(unique(a.begin(), a.end()) - a.begin());

    for (auto i = 1u; i < a.size(); ++i) {
        if (a[i] <= a[i - 1] + k) {
            ans -= cnt[a[i - 1]];
        }
    }

    cout << ans;
}
