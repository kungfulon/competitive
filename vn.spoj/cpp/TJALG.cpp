#include <bits/stdc++.h>

using namespace std;

int n, m, d[10005], lo[10005], is[10005], ans;
vector<int> a[10005];
stack<int> s;

void tarjan(int u) {
    static int cnt = 0;
    d[u] = lo[u] = cnt++;
    is[u] = 1;
    s.push(u);

    for (int v : a[u]) {
        if (d[v] == -1) {
            tarjan(v);
            lo[u] = min(lo[u], lo[v]);
        } else if (is[v]) {
            lo[u] = min(lo[u], d[v]);
        }
    }

    if (d[u] == lo[u]) {
        ++ans;

        while (s.top() != u) {
            is[s.top()] = 0;
            s.pop();
        }

        is[u] = 0;
        s.pop();
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        a[u - 1].push_back(v - 1);
    }

    memset(d, -1, sizeof(d));
    memset(lo, -1, sizeof(lo));

    for (int i = 0; i < n; ++i) {
        if (d[i] == -1) {
            tarjan(i);
        }
    }

    cout << ans;    
}
