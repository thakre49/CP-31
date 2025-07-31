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
    int ans = INT_MAX;

    for (int i = 0; i < 26; i++)
    {
        int start = 0;
        int end = n - 1;
        int tempAns = 0;
        while (start <= end)
        {
            if (s[start] == s[end])
            {
                start++;
                end--;
            }
            else
            {
                if (s[start] == ('a' + i))
                {
                    start++;
                    tempAns++;
                }
                else if (s[end] == ('a' + i))
                {
                    end--;
                    tempAns++;
                }
                else
                {
                    tempAns = INT_MAX;
                    break;
                }
            }
        }
        ans = min(tempAns, ans);
    }
    if (ans == INT_MAX)
        cout << -1;
    else
        cout << ans;
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