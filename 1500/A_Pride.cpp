#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    int ones = count(a.begin(), a.end(), 1);
    if (ones > 0) {
        cout << n - ones << "\n";
        return 0;
    }

    int best = INT_MAX;
    for (int i = 0; i < n; ++i) {
        int g = a[i];
        for (int j = i + 1; j < n; ++j) {
            g = __gcd(g, a[j]);
            if (g == 1) {
                best = min(best, j - i + 1);
                break;
            }
        }
    }

    if (best == INT_MAX)
        cout << -1 << "\n";
    else
        cout << best + n - 2 << "\n";

    return 0;
}
