#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// Sum of first n natural numbers
ll sum(ll n) {
    return n * (n + 1) / 2;
}

// Sum of decreasing sequence: start + (start - 1) + ... + (start - n + 1)
ll decreasingSum(ll start, ll n) {
    return n * (2 * start - n + 1) / 2;
}

// Modified binarySearch for increasing phase
ll binarySearchInc(ll low, ll high, ll x) {
    ll ans = high;
    while (low <= high) {
        ll mid = (low + high) / 2;
        if (sum(mid) >= x) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

// Modified binarySearch for decreasing phase
ll binarySearchDec(ll low, ll high, ll x, ll start) {
    ll ans = high;
    while (low <= high) {
        ll mid = (low + high) / 2;
        if (decreasingSum(start, mid) >= x) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

void solve() {
    ll k, x;
    cin >> k >> x;

    ll fullInc = sum(k);

    if (x <= fullInc) {
        ll t = binarySearchInc(1, k, x);
        cout << t << '\n';
    } else {
        ll remaining = x - fullInc;
        ll t = binarySearchDec(1, k - 1, remaining, k - 1);
        cout << k + t << '\n';
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
