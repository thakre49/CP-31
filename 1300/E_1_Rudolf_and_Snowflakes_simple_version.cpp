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
bool isLogBaseXIntegerGreaterThan2(double n, double x)
{
    if (n <= 0 || x <= 0 || x == 1)
        return false; // invalid log conditions

    double val = log(n) / log(x); // log base x of n

    // Check if integer within tolerance and greater than 3
    return fabs(val - round(val)) < 1e-9 && round(val) > 2;
}

void solve()
{
    int n;
    cin >> n;
    for (int i = 2; i <= 1000; i++)
    {
        int logIn = (n * (i - 1)) + 1;
        if (isLogBaseXIntegerGreaterThan2(logIn, i))
        {
            cout << "YES";
            br;
            return;
        }
    }
    cout << "NO";
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

/*
 1 3 9
 1 4 16

 (4^n - 1)/3 = 21

 1 + x + x^2 <= 10^6
 x(x+1) = 10^6

 k   n
 2   7
 3   13
 4   21


*/