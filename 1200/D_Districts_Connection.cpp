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
void printValidAns(int n, unordered_map<int, vector<int>> &m)
{
    cout << "Yes";
    br;
    vector<int> ans(n, 0);
    int i = 0;
    vector<pair<int, vector<int>>> newM;
    for (auto freqVec : m)
    {
        newM.push_back({-(freqVec.second.size()), freqVec.second});
    }
    sort(newM.begin(), newM.end());

    for (auto freqVec : newM)
    {
        for (int j = 0; j < freqVec.second.size(); j++)
        {
            ans[i] = freqVec.second[j];
            i = (i + 2);
            if (i >= n)
                i = 1;
        }
    }

    for (int i = 0; i < n - 1; i++)
    {
        cout << ans[i] << " " << ans[i + 1];
        br;
    }
}
void solve()
{
    int n;
    cin >> n;
    int maxFreq = 0;
    unordered_map<int, vector<int>> m;

    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        m[num].push_back(i + 1);
        maxFreq = max(maxFreq, static_cast<int>(m[num].size()));
    }
    if (maxFreq > (n + 1) / 2)
    {
        cout << "No";
        br;
    }
    else
        printValidAns(n, m);
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
