#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    long long ans = 0;

    for (int i = 0, dir = 1; ;) {
        if (dir == 1) {
            while (i < n - 1 && a[i + 1] >= a[i]) {
                ++i;
            }

            ans += a[i];
            dir = -1;

            if (i == n - 1) {
                break;
            }
        } else {
            while (i < n - 1 && a[i + 1] <= a[i]) {
                ++i;
            }

            if (i < n -1) {
                ans -= a[i];
                dir = 1;
            } else {
                break;
            }
        }
    }

    cout << ans;
}
