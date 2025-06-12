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

int calclateSubAns(int i, int j, vector<pair<int, int>> &freq)
{
    int maxFreq = freq[i].second;
    int tempAns = 0;
    while (i <= j)
    {
        if (freq[i].second == 1)
        {
            tempAns += maxFreq - 1;
            i++;
            if (i < freq.size() && i <= j)
                maxFreq = freq[i].second;
            else
            {
                maxFreq = 1;
            }
        }
        else
        {
            maxFreq = max(maxFreq, freq[i].second);
            i++;
        }
    }

    tempAns += maxFreq - 1;
    return tempAns;
}
void solve()
{
    int n;
    cin >> n;
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        m[num]++;
    }

    vector<pair<int, int>> freq;
    for (auto it : m)
    {
        freq.push_back({it.first, it.second});
    }
    sort(freq.begin(), freq.end());

    int ans = 0;
    int i = 0;
    int start = 0;
    int size = freq.size();
    while (i < size - 1)
    {
        if ((freq[i].first + 1 == freq[i + 1].first))
        {
            i++;
        }
        else
        {
            ans++;
            ans += calclateSubAns(start, i, freq);
            i++;
            start = i;
        }
    }

    if (start < size)
    {
        ans++;
    }

    ans += calclateSubAns(start, i, freq);

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