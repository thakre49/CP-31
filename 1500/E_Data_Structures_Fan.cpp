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
    vector<int> nums(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> nums[i];

    string s;
    cin >> s;

    int xor0 = 0;
    int xor1 = 0;
    vector<int> prefXor(n + 1, 0);

    for (int i = 0; i < n; i++)
    {
        prefXor[i + 1] = prefXor[i] ^ nums[i + 1];
        if (s[i] == '0')
            xor0 = xor0 ^ nums[i + 1];
        else
            xor1 = xor1 ^ nums[i + 1];
    }

    int q;
    cin >> q;
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 2)
        {
            int a;
            cin >> a;
            cout << (a == 0 ? xor0 : xor1) << " ";
        }
        else
        {
            int l, r;
            cin >> l >> r;
            xor0 = xor0 ^ prefXor[r] ^ prefXor[l - 1];
            xor1 = xor1 ^ prefXor[r] ^ prefXor[l - 1];
        }
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