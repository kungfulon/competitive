#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> a(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (a[i].find(a[j]) != std::string::npos) {
                swap(a[i], a[j]);
            }
        }
    }

    for (int i = 0; i < n - 1; ++i) {
        if (a[i + 1].find(a[i]) == std::string::npos) {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES\n";

    for (string s: a) {
        cout << s << '\n';
    }
}
