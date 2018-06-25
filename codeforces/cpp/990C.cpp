#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector< pair<int, int> > cnt(n);
    map< pair<int, int>, long long> xd;

    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        
        for (auto j = 0u; j < s.size(); ++j) {
            if (s[j] == '(') {
                ++cnt[i].first;
            } else {
                if (cnt[i].first) {
                    --cnt[i].first;
                } else {
                    ++cnt[i].second;
                }
            }
        }

        ++xd[cnt[i]];
    }

    long long ans = xd[{0, 0}] * xd[{0, 0}];

    for (int i = 0; i < n; ++i) {
        if (cnt[i].first > 0 && cnt[i].second == 0) {
            ans += xd[{0, cnt[i].first}];
        }
    }

    cout << ans;
}
