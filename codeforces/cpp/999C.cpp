#include <bits/stdc++.h>

using namespace std;

int id[26], d[400005];
vector<int> chars[26];

int main() {
    ios_base::sync_with_stdio(0);
    int n, k;
    string s;
    cin >> n >> k >> s;

    for (int i = 0; i < n; ++i) {
        chars[s[i] - 'a'].push_back(i);
    }

    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < 26; ++j) {
            if (id[j] < chars[j].size()) {
                d[chars[j][id[j]++]] = 1;
                break;
            }
        }
    }

    string res;

    for (int i = 0; i < n; ++i) {
        if (d[i] == 0) {
            res.push_back(s[i]);
        }
    }

    cout << res;
}
