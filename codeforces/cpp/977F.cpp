#include <bits/stdc++.h>

using namespace std;

void printReverse(int u, vector<int> &tr) {
    if (u == -1) {
        return;
    }
    
    printReverse(tr[u] - 1, tr);
    cout << u + 1 << ' ';
}

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> a(n), tr(n);
    pair<int, int> mx = { 0, 0 };

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    map< int, pair<int, int> > f;

    for (int i = 0; i < n; ++i) {
        if (!f.count(a[i] - 1)) {
            if (!f.count(a[i])) {
                f[a[i]] = { 1, i };
            }
        } else if (!f.count(a[i]) || f[a[i]].first < f[a[i] - 1].first + 1) {
            f[a[i]] = { f[a[i] - 1].first + 1, i };
            tr[i] = f[a[i] - 1].second + 1;
        }

        if (mx.first < f[a[i]].first) {
            mx = { f[a[i]].first, i };
        }
    }

    cout << mx.first << '\n';
    printReverse(mx.second, tr);
}
