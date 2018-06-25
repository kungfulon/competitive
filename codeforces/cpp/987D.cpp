#include <bits/stdc++.h>

using namespace std;

int n, m, k, s, d[100005], g[100005];
priority_queue< int, vector<int>, greater<int> > dist[100005];
vector<int> a[100005];

void bfs(int gid) {
    queue< pair<int, int> > q;

    for (int i = 1; i <= n; ++i) {
        if (g[i] != gid) {
            continue;
        }

        q.push({i, 0});
        d[i] = gid;
        dist[i].push(0);
    }

    while (!q.empty()) {
        int u = q.front().first, w = q.front().second;
        q.pop();

        for (int v: a[u]) {
            if (d[v] == gid) {
                continue;
            }

            q.push({v, w + 1});
            d[v] = gid;
            dist[v].push(w + 1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> m >> k >> s;

    for (int i = 1; i <= n; ++i) {
        cin >> g[i];
    }

    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    for (int i = 1; i <= k; ++i) {
        bfs(i);
    }

    for (int i = 1; i <= n; ++i) {
        long long ans = 0;

        for (int j = 1; j <= s; ++j) {
            ans += dist[i].top();
            dist[i].pop();
        }

        cout << ans << ' ';
    }
}
