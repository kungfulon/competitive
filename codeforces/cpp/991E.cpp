#include <bits/stdc++.h>

using namespace std;

int cnt[10];
long long ans, fact[20];

void work(int i, int sz, long long xd) {
    if (i == 10) {
        if (cnt[0] == 0) {
            ans += fact[sz] / xd;
        } else {
            for (int i = 1; i <= cnt[0]; ++i) {
                ans += fact[sz + i] / (xd * fact[i]) - fact[sz + i - 1] / (xd * fact[i - 1]);
            }
        }
        
        return;
    }

    if (cnt[i] == 0) {
        work(i + 1, sz, xd);
        return;
    }

    for (int j = 1; j <= cnt[i]; ++j) {
        work(i + 1, sz + j, xd * fact[j]);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    long long n;
    cin >> n;
    string s = to_string(n);
    fact[0] = 1;

    for (int i = 1; i < 20; ++i) {
        fact[i] = fact[i - 1] * i;
    }

    for (char cc : s) {
        ++cnt[cc - '0'];
    }

    work(1, 0, 1);
    cout << ans;
}
