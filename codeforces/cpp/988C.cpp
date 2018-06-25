#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int k;
    cin >> k;
    vector< vector<int> > a(k);
    map< int, pair< pair<int, int>, pair<int, int> > > m;

    for (int i = 0; i < k; ++i) {
        int n, sum = 0;
        cin >> n;

        for (int j = 0; j < n; ++j) {
            int x;
            cin >> x;
            a[i].push_back(x);
            sum += x;
        }

        for (int j = 0; j < n; ++j) {
            int rSum = sum - a[i][j];
            int cnt = m.count(rSum);

            if (cnt == 0) {
                m.insert({ rSum, { {i, j}, {-1, -1} } });
            } else if (m[rSum].second.first == -1 && i != m[rSum].first.first) {
                m[rSum].second = {i, j};
            }
        }
    }

    for (auto it = m.begin(); it != m.end(); ++it) {
        if (it->second.second.first != -1) {
            cout << "YES\n" << it->second.first.first + 1 << ' ' << it->second.first.second + 1 << '\n' << it->second.second.first + 1 << ' ' << it->second.second.second + 1;
            return 0;
        }
    }

    cout << "NO";
}
