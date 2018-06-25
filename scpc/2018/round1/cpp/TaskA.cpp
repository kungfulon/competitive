#include <bits/stdc++.h>

using namespace std;

int a[200005];

int solution() {
    int n, k;
    cin >> n >> k;
    priority_queue< int, vector<int>, greater<int> > q;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a, a + n);

    for (int i = 0; i < n; ++i) {
        if (!q.empty() && a[i] - q.top() > k) {
            q.pop();
        }

        q.push(a[i]);
    }

    return q.size();
}

int main() {
    ios_base::sync_with_stdio(0);
    setbuf(stdout, NULL);
    int t;
    cin >> t;

    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << '\n' << solution() << '\n';
    }
}
