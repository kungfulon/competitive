#include <bits/stdc++.h>

using namespace std;

int n, k, ans;
list<int> l;

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> k;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        l.push_back(x);
    }

    while (!l.empty()) {
        if (*l.begin() <= k) {
            ++ans;
            l.erase(l.begin());
            continue;
        }

        if (*l.rbegin() <= k) {
            ++ans;
            auto it = l.end();
            l.erase(--it);
            continue;
        }

        break;
    }

    cout << ans;
}
