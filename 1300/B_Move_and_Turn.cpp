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
    int n;
    cin >> n;
    if (n % 2)
    {
        cout << 2 * ((n / 2) + 1) * ((n - n / 2) + 1);
        br;
    }
    else
    {
        cout << (n / 2 + 1) * (n / 2 + 1);
        br;
    }
}

int main()
{

    solve();

    return 0;
}