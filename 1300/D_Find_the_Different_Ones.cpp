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
void resolveQuery(vector<pair<int, int>> &intervals, int l, int r, int size)
{
    int n = intervals.size();
    int start = 0;
    int end = n - 1;

    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (intervals[mid].first <= l && intervals[mid].second >= r)
        {
            cout << -1 << " " << -1;
            br;
            return;
        }
        else if (intervals[mid].first > r)
        {
            end = mid - 1;
        }
        else if (intervals[mid].second < l)
        {
            start = mid + 1;
        }

        else
        {

            if (intervals[mid].first > l && r >= intervals[mid].first)
            {
                cout << intervals[mid].first - 1 << " " << intervals[mid].first;
                br;
                return;
            }
            else if (intervals[mid].second >= l && r > intervals[mid].second)
            {
                cout << intervals[mid].second << " " << intervals[mid].second + 1;
                br;
                return;
            }
        }
    }
    cout << l << " " << l + 1;
    br;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    int start = 0;
    int end = 0;
    vector<pair<int, int>> intervals;

    while (end < n)
    {
        if (nums[start] == nums[end])
        {
            end++;
        }
        else
        {
            if (end - start > 1)
            {
                intervals.push_back({start + 1, end});
            }
            start = end;
        }
    }
    if (end - start > 1)
    {
        intervals.push_back({start + 1, end});
    }

    int q;
    cin >> q;

    while (q--)
    {
        int l, r;
        cin >> l >> r;
        resolveQuery(intervals, l, r, n);
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
