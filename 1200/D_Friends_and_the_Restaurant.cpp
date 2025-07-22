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
    vector<int> want(n);
    vector<int> have(n);
    for (int i = 0; i < n; i++)
        cin >> want[i];

    for (int i = 0; i < n; i++)
        cin >> have[i];

    vector<int> rich;
    vector<int> poor;
    for (int i = 0; i < n; i++)
    {
        if (want[i] <= have[i])
            rich.push_back(have[i] - want[i]);
        else
            poor.push_back(want[i] - have[i]);
    }

    sort(rich.begin(), rich.end());
    sort(poor.begin(), poor.end());
    int ans = 0;
    int richRemain = 0;
    int i = 0;
    int j = 0;
    while (i < rich.size() && j < poor.size())
    {
        if (poor[j] <= rich[i])
        {
            ans++;
            i++;
            j++;
        }
        else if (poor[j] > rich[i])
        {
            richRemain++;
            i++;
        }
    }

    ans += (rich.size() - i + richRemain) / 2;
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