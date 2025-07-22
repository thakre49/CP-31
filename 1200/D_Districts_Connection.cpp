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

void printCurrent(int par, vector<int> &childs, bool first)
{
    int n = childs.size();

    for (int i = 0; i < n; i++)
    {
        if (first && i == 0)
            continue;

        cout << par << " " << childs[i];
        br;
    }
}
void solve()
{
    int n;
    cin >> n;
    vector<int> gangs(n + 1);
    unordered_map<int, vector<int>> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> gangs[i];
        m[gangs[i]].push_back(i);
    }
    if (m.size() == 1 && gangs.size() > 1)
    {
        cout << "NO";
        br;
        return;
    }

    cout << "YES";
    br;

    int par = -1;
    int firstNum = 0;

    for (auto it : m)
    {
        if (par == -1)
        {
            par = it.second[0];
            firstNum = it.first;
        }
        else
        {
            printCurrent(par, it.second, false);
            par  = it.second[0];
        }
    }
    printCurrent(par, m[firstNum], true);
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