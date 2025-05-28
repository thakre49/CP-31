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
    int rs = (n * (n - 1)) / 2;
    vector<int> ans;
    vector<int> shuffledArray(rs);
    map<int, int, greater<int>> freq;
    for (int i = 0; i < rs; i++)
    {
        cin >> shuffledArray[i];
        freq[shuffledArray[i]]++;
    }

    auto it = freq.begin();
    int firstNum = it->first;
    ans.push_back(it->first);
    ans.push_back(it->first);
    freq[it->first]--;

    int i = 2;

    for (auto it : freq)
    {
        int freqNum = it.second;
        while (freqNum)
        {
            ans.push_back(it.first);
            freqNum = freqNum - i;
            i++;
        }
    }
    for (auto i : ans)
    {
        cout << i << " ";
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