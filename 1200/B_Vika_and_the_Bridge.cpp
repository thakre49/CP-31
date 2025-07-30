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

class Node
{
public:
    int prev;
    int firstMax;
    int secondMax;

    Node()
    {
        prev = -1;
        firstMax = 0;
        secondMax = 0;
    }
};

void updateSteps(Node &element, int currentSteps)
{
    if (currentSteps > element.firstMax)
    {
        element.secondMax = element.firstMax;
        element.firstMax = currentSteps;
    }
    else
    {
        element.secondMax = max(element.secondMax, currentSteps);
    }
}

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    map<int, Node> freq;
    for (int i = 0; i < n; i++)
    {
        freq[nums[i]] = Node();
    }

    for (int i = 0; i < n; i++)
    {
        int prevPos = freq[nums[i]].prev;
        int currentSteps = i - prevPos - 1;
        updateSteps(freq[nums[i]], currentSteps);
        freq[nums[i]].prev = i;
    }
    for (int i = 0; i < n; i++)
    {
        int prevPos = freq[nums[i]].prev;
        int currentSteps = n - prevPos - 1;
        updateSteps(freq[nums[i]], currentSteps);
        freq[nums[i]].prev = n;
    }

    int ans = INT_MAX;

    for (auto it : freq)
    {
        int currentChanged = it.second.firstMax / 2;
        ans = min(ans, max(currentChanged, it.second.secondMax));
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