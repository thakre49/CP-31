#include <bits/stdc++.h>
using namespace std;

bool helper(int node, vector<vector<int>> &tree,
            vector<int> &remove, vector<int> &ans)
{

    bool temp = true;
    for (auto it : tree[node])
    {
        temp = (temp & helper(it, tree, remove, ans));
    }

    if (temp && remove[node])
    {
        ans.push_back(node);
        return true;
    }
    else if (remove[node])
        return true;
    return false;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> tree(n + 1);
    vector<int> remove(n + 1, 0);
    int root;
    for (int i = 1; i <= n; i++)
    {
        int par, status;
        cin >> par >> status;
        if (par == -1)
        {
            root = i;
            continue;
        }
        tree[par].push_back(i);
        remove[i] = status;
    }

    vector<int> ans;
    bool temp = helper(root, tree,
                       remove, ans);
    if (ans.size() == 0)
    {
        cout << -1;
        return 0;
    }
    sort(ans.begin(), ans.end());

    for (auto it : ans)
    {
        cout << it << " ";
    }
   

    return 0;
}