#include <bits/stdc++.h>

using namespace std;

int n, m, s, cnt, cntScc, d[5005], scc[5005], dd[5005], lo[5005], inStack[5005], cntIn[5005];
vector<int> a[5005], b[5005];
stack<int> st;

void tarjan(int u) {
    static int iter = 0;
    dd[u] = lo[u] = ++iter;
    inStack[u] = 1;
    st.push(u);

    for (int v : a[u]) {
        if (dd[v] == 0) {
            tarjan(v);
            lo[u] = min(lo[u], lo[v]);
        } else if (inStack[v]) {
            lo[u] = min(lo[u], dd[v]);
        }
    }

    if (dd[u] == lo[u]) {
        ++cntScc;

        while (st.top() != u) {
            inStack[st.top()] = 0;
            scc[st.top()] = cntScc;
            st.pop();
        }

        inStack[u] = 0;
        scc[u] = cntScc;
        st.pop();
    }
}

void dfs(int u) {
    d[u] = cnt;

    for (int v : b[u]) {
        if (!d[v]) {
            dfs(v);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> m >> s;

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
    }

    for (int u = 1; u <= n; ++u) {
        if (!dd[u]) {
            tarjan(u);
        }
    }

    for (int u = 1; u <= n; ++u) {
        for (int v : a[u]) {
            if (scc[v] != scc[u]) {
                ++cntIn[scc[v]];
                b[scc[u]].push_back(scc[v]);
            }
        }
    }

    ++cnt;
    dfs(scc[s]);

    for (int u = 1; u <= cntScc; ++u) {
        if (!d[u] && !cntIn[u]) {
            ++cnt;
            dfs(u);
        }
    }

    cout << cnt - 1;
}
