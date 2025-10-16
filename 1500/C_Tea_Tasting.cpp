#include <bits/stdc++.h>
using namespace std;

// Aliases
using ll = long long;
using lld = long double;
using ull = unsigned long long;

// Constants
const lld pi = 3.141592653589793238;
const ll mod = 1e9 + 7;

// TypeDefs
typedef pair<int, int> pri;
typedef unordered_map<int, int> umi;
typedef map<int, int> mi;

// Macros
#define pb push_back
#define br cout << "\n"
//****************************************************************

void binarySearch(int start, int n, vector<ll> &a, vector<ll> &prefSum,
                  vector<ll> &ans, vector<ll> &chunks)
{
    int low = start;
    int high = n;
    int temp = n + 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        ll num = prefSum[mid] - prefSum[start - 1];

        if (num < a[start])
        {
            low = mid + 1;
        }
        else
        {
            temp = mid;
            high = mid - 1;
        }
    }

    if (temp == start)
    {
        chunks[start] += a[temp];
        return;
    }
    if (temp == n + 1)
    {
        ans[start] += 1;
    }
    else
    {
        ans[start] += 1;
        ans[temp] -= 1;

        ll rem = a[start] - (prefSum[temp - 1] - prefSum[start - 1]);
        chunks[temp] += rem;
    }
}

void solve()
{
    int n;
    cin >> n;
    vector<ll> a(n + 1, 0), b(n + 1, 0);

    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];

    vector<ll> prefSum(n + 2, 0), ans(n + 2, 0), chunks(n + 2, 0);

    for (int i = 1; i <= n; i++)
        prefSum[i] = prefSum[i - 1] + b[i];

    for (int i = 1; i <= n; i++)
        binarySearch(i, n, a, prefSum, ans, chunks);

    for (int i = 1; i <= n; i++)
        ans[i] = ans[i - 1] + ans[i];

    vector<ll> finalAns(n + 1, 0);
    for (int i = 1; i <= n; i++)
        finalAns[i] = ans[i] * b[i] + chunks[i];

    for (int i = 1; i <= n; i++)
        cout << finalAns[i] << " ";
    br;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
