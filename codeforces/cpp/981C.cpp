#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int n, center = 0;
    cin >> n;
    vector<int> d(n + 1), leafs;
    vector< vector<int> > a(n + 1);

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    for (int u = 1; u <= n; ++u) {
        if (a[u].size() > 2) {
            if (center) {
                cout << "No";
                return 0;
            }

            center = u;
        } else if (a[u].size() == 1) {
            leafs.push_back(u);
        }
    }

    if (center) {
        cout << "Yes\n" << leafs.size() << '\n';

        for (size_t i = 0; i < leafs.size(); ++i) {
            cout << center << ' ' << leafs[i] << '\n';
        }
    } else {
        cout << "Yes\n1\n" << leafs[0] << ' ' << leafs[1];
    }
}
