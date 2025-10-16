/*
(3,2) (4,3) (5,1) (6,4)

(1,1) (2,3) (3,4) (4,2) (4,6) (6,5) (9,7)
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
// (3,2) (4,3) (5,1) (6,4)
void solve()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    vector<pair<int, int>> numInd(n);

    for (int i = 0; i < n; i++)
        numInd[i] = {nums[i], i + 1};
    sort(numInd.begin(), numInd.end());
    vector<int> tempAns(n + 1, 0);
    int ans = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = numInd[i].second; j <= n; j = j + numInd[i].second)
        {
            if (nums[j - 1] != numInd[i].first)
                tempAns[numInd[i].second] = max(tempAns[numInd[i].second], 1 + tempAns[j]);
        }
        //cout << tempAns[numInd[i].second] << " ";
        tempAns[numInd[i].second] = max(tempAns[numInd[i].second], 1);
        ans = max(ans, tempAns[numInd[i].second]);
    }

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