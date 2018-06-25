#include <bits/stdc++.h>

using namespace std;

int n, a[100005], d[200005];

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    int ans = 0;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        
        if (a[i] != 0 && !d[a[i] + 100001]) {
            d[a[i] + 100001] = 1;
            ++ans;
        }
    }

    cout << ans;
}
