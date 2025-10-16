#include <bits/stdc++.h>
using namespace std;

#define MOD 998244353
#define MAX 200005

using ll = long long;

// Precomputed factorials and inverse factorials
ll fact[MAX], invFact[MAX];

// Modular exponentiation
ll power(ll x, ll y) {
    ll res = 1;
    x %= MOD;
    while (y > 0) {
        if (y & 1) res = res * x % MOD;
        x = x * x % MOD;
        y >>= 1;
    }
    return res;
}

// Precompute factorials and inverse factorials
void precompute() {
    fact[0] = invFact[0] = 1;
    for (ll i = 1; i < MAX; i++) {
        fact[i] = fact[i - 1] * i % MOD;
        invFact[i] = power(fact[i], MOD - 2);
    }
}

ll C(ll n, ll k) {
    if (k < 0 || k > n) return 0;
    return fact[n] * invFact[k] % MOD * invFact[n - k] % MOD;
}

void solve() {
    string s;
    cin >> s;
    int n = s.size();

    vector<int> groups;
    int cnt = 1;

    // Build group sizes
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i - 1]) {
            cnt++;
        } else {
            groups.push_back(cnt);
            cnt = 1;
        }
    }
    groups.push_back(cnt);

    ll totalRemovals = 0;
    ll ways = 1;

    for (int group : groups) {
        if (group > 1) {
            totalRemovals += (group - 1);
            ways = ways * C(group, group - 1) % MOD;
        }
    }

    // Multiply by totalRemovals! to count permutations of operations
    ways = ways * fact[totalRemovals] % MOD;

    cout << totalRemovals << " " << ways << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    precompute();

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
