#include <bits/stdc++.h>

using namespace std;

void dfs(int u, int p, vector< vector<int> > &a, vector<int> &d, int curCycleSize, int &numCycles, int &maxCycleSize, int &numVisited) {
    d[u] = 1;
    ++numVisited;

    for (int v: a[u]) {
        if (d[v]) {
            if (v != p && curCycleSize > 2) {
                ++numCycles;
                maxCycleSize = max(maxCycleSize, curCycleSize);
            }
        } else {
            dfs(v, u, a, d, curCycleSize + 1, numCycles, maxCycleSize, numVisited);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    int n, m, ans = 0;
    cin >> n >> m;
    vector< vector<int> > a(n + 1);
    vector<int> d(n + 1);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    for (int u = 1; u <= n; ++u) {
        if (d[u]) {
            continue;
        }

        int numCycles = 0, maxCycleSize = 0, numVisited = 0;
        dfs(u, 0, a, d, 1, numCycles, maxCycleSize, numVisited);
        ans += numCycles == 1 && maxCycleSize == numVisited;
    }

    cout << ans;
}
