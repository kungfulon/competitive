#include <bits/stdc++.h>

using namespace std;

int getRoot(int u, vector<int> &r) {
    if (r[u] != u) {
        r[u] = getRoot(r[u], r);
    }

    return r[u];
}

void mergeTree(int u, int v, vector<int> &r, vector<int> &size) {
    u = getRoot(u, r);
    v = getRoot(v, r);

    if (u != v) {
        r[v] = u;
        size[u] += size[v];
    }
}

int main() {
    ios_base::sync_with_stdio(0);

    int n, maxGroupSize = 0, numMaxSize = 0, numNotMaxSize = 0, maxGroups = 0, k = 0;
    cin >> n;
    vector<int> a(n), r(n), gSize(n);
    vector< pair<int, int> > b(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        b[i].first = a[i];
        b[i].second = i;
        r[i] = i;
        gSize[i] = 1;
    }

    sort(b.begin(), b.end());
    
    for (int i = 0; i < n; ++i) {
        int mergeLeft = 0, mergeRight = 0;

        // merge left
        if (b[i].second > 0 && a[b[i].second - 1] <= b[i].first) {
            mergeTree(b[i].second - 1, b[i].second, r, gSize);
            mergeLeft = 1;
        }

        // merge right
        if (b[i].second < n - 1 && a[b[i].second + 1] <= b[i].first) {
            mergeTree(b[i].second, b[i].second + 1, r, gSize);
            mergeRight = 1;
        }

        // check
        int curGroupSize = gSize[getRoot(b[i].second, r)];

        if (maxGroupSize < curGroupSize) {
            maxGroupSize = curGroupSize;
            numNotMaxSize = numMaxSize - mergeLeft - mergeRight;
            numMaxSize = 1;
        } else if (maxGroupSize == curGroupSize) {
            ++numMaxSize;
            numNotMaxSize -= mergeLeft + mergeRight;
        } else if (!mergeLeft && !mergeRight) {
            ++numNotMaxSize;
        }

        if (numNotMaxSize == 0) {
            if (maxGroups < numMaxSize) {
                maxGroups = numMaxSize;
                k = b[i].first + 1;
            }
        }
    }

    cout << k;
}
