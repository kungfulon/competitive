#include <bits/stdc++.h>

using namespace std;

int n, m, ans, c[200005];
long long a[200005];
stack<int> st[200005];
set<int> notEnough;

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ++c[a[i] % m];
        st[a[i] % m].push(i);
    }

    int cc = n / m;

    for (int i = 0; i < m; ++i) {
        if (c[i] < cc) {
            notEnough.insert(i);
        }
    }

    long long ans = 0;

    for (int i = 0; i < m; ++i) {
        while (c[i] > cc) {
            auto itr = notEnough.upper_bound(i);

            if (itr == notEnough.end()) {
                itr = notEnough.begin();
            }

            int step;

            if (*itr > i) {
                step = *itr - i;
            } else {
                step = m - i + *itr;
            }

            --c[i];
            int u = st[i].top();
            st[i].pop();
            ++c[*itr];
            a[u] += step;
            ans += step;

            if (c[*itr] == cc) {
                notEnough.erase(itr);
            }
        }
    }

    cout << ans << '\n';

    for (int i = 0; i < n; ++i) {
        cout << a[i] << ' ';
    }
}
