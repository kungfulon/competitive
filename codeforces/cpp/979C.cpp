#include <bits/stdc++.h>

using namespace std;

int n, x, y, d[300005], f[300005], bad[300005];
vector<int> a[300005];

void dfs(int u) {
    d[u] = 1;

    for (int v: a[u]) {
        if (d[v]) {
            continue;
        }

        dfs(v);
        f[u] += f[v] + 1;
        
        if (bad[v] || v == x) {
            bad[u] = v;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> x >> y;

    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    dfs(y);
    cout << (long long)n * (n - 1) - (long long)(f[x] + 1) * (f[y] - f[bad[y]]);
}
