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

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    ll pos = 0;
    ll neg = 0;
    ll ansP = 0;
    ll ansN = 0;

    for (int i = 0; i < n; i++)
    {
        int cPos = 0;
        int cNeg = 0;
        if (nums[i] > 0)
        {
            cPos = pos;
            cPos++;
            cNeg = neg;
        }
        else
        {
            cPos = neg;
            cNeg = pos;
            cNeg++;
        }
        pos = cPos;
        neg = cNeg;
        ansP += pos;
        ansN += neg;
    }
    cout << ansN << " " << ansP;

    return 0;
}
