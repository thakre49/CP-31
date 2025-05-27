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
long long gcd(long long a, long long b)
{
    while (b != 0)
    {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}
void solve()
{
    long long n, x, y;
    cin >> n >> x >> y;
    long long lcm = (x / gcd(x, y)) * y;
    long long commonNumbers = n / lcm;

    long long i = n / y - commonNumbers;

    long long toSub = (i * (i + 1)) / 2;

    long long j = n - (n / x - commonNumbers);
    long long toAdd = (n * (n + 1)) / 2 - (j * (j + 1)) / 2;

    cout << toAdd - toSub;
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