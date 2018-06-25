// Peg Game https://www.facebook.com/hackercup/problem/157960964217186/
#include <bits/stdc++.h>

using namespace std;

double bfs(int startCol, int endCol, vector< vector<int> > &a, int n, int m) {
    queue< pair< pair<int, int>, double > > q;
    q.push({{0, startCol}, 1.0});
    double maxProb = -2.0;

    while (!q.empty()) {
        pair<int, int> u = q.front().first;
        double prob = q.front().second;
        q.pop();
        ++u.first;

        if (u.first == n) {
            if (u.second == endCol) {
                maxProb = max(maxProb, prob);
            }

            continue;
        }

        if (a[u.first][u.second]) {
            q.push({{u.first, u.second}, prob});
        } else {
            if (a[u.first][u.second - 1] == 1 && a[u.first][u.second + 1] == 1) {
                q.push({{u.first, u.second - 1}, prob / 2.0});
                q.push({{u.first, u.second + 1}, prob / 2.0});
            } else if (a[u.first][u.second - 1] == 1) {
                q.push({{u.first, u.second - 1}, prob});
            } else if (a[u.first][u.second + 1] == 1) {
                q.push({{u.first, u.second + 1}, prob});
            }
        }
    }

    return maxProb;
}

pair<int, double> solution() {
    int n, m, k, q;
    cin >> n >> m >> k >> q;
    m = (m - 1) * 2 + 1;
    vector< vector<int> > a(n);
    
    for (int i = 0; i < n; ++i) {
        a[i].resize(m);

        for (int j = 1 + (i % 2); j < m - (i % 2); j += 2) {
            a[i][j] = 1;
        }
    }

    for (int i = 0; i < q; ++i) {
        int u, v;
        cin >> u >> v;
        a[u][v * 2 + (u % 2)] = 1;
    }

    pair<int, double> ans = {-1, -1.0};

    for (int i = 1; i < m; i += 2) {
        double prob = bfs(i, k * 2 + 1, a, n, m);

        if (ans.second < prob) {
            ans = {i / 2, prob};
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;

    for (int i = 1; i <= t; ++i) {
        pair<int, double> ans = solution();
        cout << "Case #" << i << ": " << ans.first << ' ' << ans.second << '\n';
    }
}

