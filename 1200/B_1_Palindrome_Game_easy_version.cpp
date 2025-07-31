/**
 1) Length is even
 -> zeros even -> BOB
 -> zeros odd  -> BOB





 2) Length is Odd
 -> zeros even -> Alice
 -> zeros odd  -> BOB

 1 0 1




 */

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
    string s;
    cin >> s;
    int zeros = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
            zeros++;
    }
    if (zeros == 0)
    {
        cout << "DRAW";
        br;
        return;
    }
    if (zeros == 1)
    {
        cout << "BOB";
        br;
        return;
    }

    if (zeros % 2)
    {
        cout << "ALICE";
        br;
    }
    else
    {

        cout << "BOB";
        br;
    }
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
