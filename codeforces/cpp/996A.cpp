#include <bits/stdc++.h>

using namespace std;

int cash[] = { 100, 20, 10, 5, 1 };

int main() {
    ios_base::sync_with_stdio(0);
    int n, ans = 0;
    cin >> n;

    for (int i = 0; i < 5; ++i) {
        while (n >= cash[i]) {
            ++ans;
            n -= cash[i];
        }

        if (n == 0) {
            break;
        }
    }

    cout << ans;
}
