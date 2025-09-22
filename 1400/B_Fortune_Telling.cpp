#include <bits/stdc++.h>
using namespace std;

// Aliases
using ll = long long;
using lld = long double;
using ull = unsigned long long;

// Constants
const lld pi = 3.141592653589793238;
const ll mod = 1e9 + 7;

// TypeDEf
typedef pair<int, int> pri;
typedef unordered_map<int, int> umi;
typedef map<int, int> mi;

// Macros
#define pb push_back
#define br cout << "\n"
//****************************************************************
void solve()
{
    ll n, x, y;
    cin >> n >> x >> y;
    ll countOdd = 0;
    ll num;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        if (num % 2)
            countOdd++;
    }
    countOdd %= 2;
    ll a = ((x % 2) + countOdd) % 2;
    ll b = (((x + 3) % 2) + countOdd) % 2;

    y %= 2;
    if (y == a)
        cout << "Alice";
    else
        cout << "Bob";
    br;
}

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        solve();
    }

    return 0;
}