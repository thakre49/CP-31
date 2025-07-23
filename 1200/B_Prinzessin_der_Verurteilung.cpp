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

    for (char c = 'a'; c <= 'z'; c++)
    {
        if (s.find(c) == std::string::npos)
        {
            cout << c;
            br;
            return;
        }
    }

    for (char c1 = 'a'; c1 <= 'z'; c1++)
    {

        for (char c2 = 'a'; c2 <= 'z'; c2++)
        {
            string temp;
            temp.push_back(c1);
            temp.push_back(c2);
            if (s.find(temp) == std::string::npos)
            {
                cout << temp;
                br;
                return;
            }
        }
    }

    for (char c1 = 'a'; c1 <= 'z'; c1++)
    {
        for (char c2 = 'a'; c2 <= 'z'; c2++)
        {

            for (char c3 = 'a'; c3 <= 'z'; c3++)
            {
                string temp;
                temp.push_back(c1);
                temp.push_back(c2);
                temp.push_back(c3);
                if (s.find(temp) == std::string::npos)
                {
                    cout << temp;
                    br;
                    return;
                }
            }
        }
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