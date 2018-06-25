#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int n, m;
    map<int, int> mp;
    cin >> n;
    
    for (int i = 0; i < n; ++i) {
        int u, v;
        cin >> u >> v;

        if (!mp.count(u)) {
            mp[u] = v;
        } else {
            mp[u] = max(mp[u], v);
        }
    }

    cin >> m;

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;

        if (!mp.count(u)) {
            mp[u] = v;
        } else {
            mp[u] = max(mp[u], v);
        }
    }

    long long ans = 0;

    for (auto it = mp.begin(); it != mp.end(); ++it) {
        ans += it->second;
    }

    cout << ans;
}
