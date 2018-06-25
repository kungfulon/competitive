#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    n *= 2;
    vector<int> a(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int ans = 0;

    for (int i = 0; i < n; i += 2) {
        if (a[i] == a[i + 1]) {
            continue;
        }

        for (int j = i + 1; j < n; ++j) {
            if (a[i] == a[j]) {
                for (int k = j - 1; k > i; --k) {
                    ++ans;
                    swap(a[k], a[k + 1]);
                }

                break;
            }
        }
    }

    cout << ans;
}
