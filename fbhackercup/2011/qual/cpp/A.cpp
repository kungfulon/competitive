// Double Squares https://www.facebook.com/hackercup/problem/112921602098268/
#include <bits/stdc++.h>

using namespace std;

int solution() {
    int n, ans = 0;
    cin >> n;
    int sqrtN = sqrt(n);
    
    for (int i = 0; i <= sqrtN; ++i) {
        int i2 = i * i;
        int rem = n - i2;
        int sqrtRem = sqrt(rem);

        if (i2 > rem) {
            break;
        }

        if (sqrtRem * sqrtRem == rem) {
            ++ans;
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": " << solution() << '\n';
    }
}
