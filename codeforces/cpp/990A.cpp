#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n, m, a, b;
    cin >> n >> m >> a >> b;

    if (n % m == 0) {
        cout << 0;
        return 0;
    }

    long long costBuild = a * (m * (n / m + 1) - n);
    long long costDemolish = b * (n % m);
    cout << min(costBuild, costDemolish);
}
