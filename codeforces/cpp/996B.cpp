#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> a(n);
    int minTime = 0, ans = -1;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        int gateWhenItsEmpty = a[i] % n;
        int timeToThisGate = a[i];

        if (i < gateWhenItsEmpty) {
            timeToThisGate += n - gateWhenItsEmpty + i;
        } else if (i > gateWhenItsEmpty) {
            timeToThisGate += i - gateWhenItsEmpty;
        }
        
        if (ans == -1 || minTime > timeToThisGate) {
            ans = i;
            minTime = timeToThisGate;
        }
    }

    cout << ans + 1;
}
