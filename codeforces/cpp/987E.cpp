#include <bits/stdc++.h>

using namespace std;

#define kl (k << 1)
#define kr (kl | 1)

class SegmentTree {
public:
    SegmentTree(int size) : n(size) {
        dat.resize(4 * size + 5);
    }

    void inc(int i) {
        if (i < 1 || i > n) {
            return;
        }

        update(i, 1, 1, n, 1);
    }

    int calc(int l, int r) {
        if (l > r) {
            return 0;
        }

        return query(l, r, 1, n, 1);
    }

private:
    int n;
    vector<int> dat;

    void update(int u, int v, int l, int r, int k) {
        if (u < l || u > r) {
            return;
        }

        if (l == u && u == r) {
            dat[k] += v;
            return;
        }
        
        int c = (l + r) >> 1;
        update(u, v, l, c, kl);
        update(u, v, c + 1, r, kr);
        dat[k] = dat[kl] + dat[kr];
    }

    int query(int u, int v, int l, int r, int k) {
        if (v < l || u > r) {
            return 0;
        }

        if (u <= l && r <= v) {
            return dat[k];
        }

        int c = (l + r) >> 1;
        return query(u, v, l, c, kl) + query(u, v, c + 1, r, kr);
    }
};

int main() {
    int n;
    long long numInverse = 0;
    cin >> n;
    SegmentTree t(n);

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        numInverse += t.calc(x + 1, n);
        t.inc(x);
    }

    if (numInverse % 2 == (3 * n) % 2) {
        cout << "Petr";
    } else {
        cout << "Um_nik";
    }
}
