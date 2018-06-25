#include <bits/stdc++.h>

using namespace std;

int sol1(int n, int m, vector< unordered_set<int> > &a, vector<int> &ans) {
    int minDist = INT_MAX;
    vector<int> p(n);

    for (int i = 0; i < n; ++i) {
        p[i] = i;
    }

    do {
        int dist = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (a[p[i]].count(p[j])) {
                    dist += j - i;
                }
            }
        }

        if (minDist > dist) {
            minDist = dist;
            ans = p;
        }
    } while (next_permutation(p.begin(), p.end()));

    return minDist;
}

int solution(vector<int> &ans) {
    int n, m;
    cin >> n >> m;
    vector< unordered_set<int> > a(n);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        a[u].insert(v);
        a[v].insert(u);
    }

    if (n < 9) {
        return sol1(n, m, a, ans);
    }

    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    setbuf(stdout, NULL);
    int t;
    cin >> t;
    
    for (int i = 1; i <= t; ++i) {
        vector<int> ans;
        cout << "Case #" << i << '\n' << solution(ans) << '\n';

        for (int v : ans) {
            cout << v << ' ';
        }

        cout << '\n';
    }
}
