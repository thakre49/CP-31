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
    vector<pair<int, int>> intervals(n);

    for (int i = 0; i < n; i++)
    {
        int start, end;
        cin >> start >> end;
        intervals[i] = {start, end};
    }
    sort(intervals.begin(), intervals.end());

    int tv1 = -1;
    int tv2 = -1;

    for (int i = 0; i < n; i++)
    {
        int start = intervals[i].first;
        int end = intervals[i].second;

        if (start <= tv1 && start <= tv2)
        {
            cout << "NO";
            return;
        }
        else if (start > tv1)
        {
            tv1 = end;
        }
        else if (start > tv2)
            tv2 = end;
    }

    cout << "YES";
}

int main()
{
    solve();
    return 0;
}