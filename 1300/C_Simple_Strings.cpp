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
    string s;
    cin >> s;
    int n = s.length();

    for (int i = 0; i < n - 2; i++)
    {
        if (s[i] == s[i + 1])
        {
            for (int j = 0; j < 3; j++)
            {
                if ((s[i] != ('a' + j)) && (s[i + 2] != ('a' + j)))
                {

                    s[i + 1] = 'a' + j;
                    break;
                }
            }
        }
    }
    if (s[n - 2] == s[n - 1])
    {
        if (s[n - 2] == 'a')
            s[n - 1] = 'b';
        else
            s[n - 1] = 'a';
    }

    cout << s;
    br;
}

int main()
{
    solve();

    return 0;
}

/*
ca*a*c
ca*a*ac
*/