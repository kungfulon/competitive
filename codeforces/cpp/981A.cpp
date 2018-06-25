#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(string &s) {
    if (s.size() == 0) {
        return false;
    }

    for (size_t i = 0, j = s.size() - 1; i < j; ++i, --j) {
        if (s[i] != s[j]) {
            return false;
        }
    }

    return true;
}

int main() {
    string s;
    cin >> s;
    size_t ans = 0;

    for (size_t i = 0; i < s.size(); ++i) {
        string t;

        for (size_t j = i; j < s.size(); ++j) {
            t.push_back(s[j]);

            if (!isPalindrome(t)) {
                ans = max(ans, t.size());
            }
        }
    }

    cout << ans;
}
