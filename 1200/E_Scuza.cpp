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
    int n, q;
    cin >> n >> q;
    vector<long long> stairs(n);
    vector<int> legs(q);

    for (int i = 0; i < n; i++)
        cin >> stairs[i];

    set<int> sortedLegs;
    for (int i = 0; i < q; i++)
    {
        cin >> legs[i];
        sortedLegs.insert(legs[i]);
    }

    vector<int> tempLegs;

    for (auto it : sortedLegs)
    {
        tempLegs.push_back(it);
    }
    vector<long long> tempAns(tempLegs.size(), 0);

    long long maxTil = 0;
    for (int i = 0; i < n; i++)
    {
        maxTil = max(maxTil, stairs[i]);
        auto it = lower_bound(tempLegs.begin(), tempLegs.end(), maxTil);
        if (it != tempLegs.end())
        {
            tempAns[it - tempLegs.begin()] += stairs[i];
        }
    }
    map<long long, long long> finalAns;
    finalAns[tempLegs[0]] = tempAns[0];

    for (int i = 1; i < tempAns.size(); i++)
    {

        tempAns[i] += tempAns[i - 1];
        finalAns[tempLegs[i]] = tempAns[i];
    }

    for (int i = 0; i < q; i++)
    {
        cout << finalAns[legs[i]] << " ";
    }
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