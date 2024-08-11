#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> adj_list;
vector<vector<int>> sub_weight;
vector<int> weight;
vector<bool> visited;

void dfs(int u, vector<vector<int>> &adj, vector<bool> &vis)
{
    vis[u] = true;
    sub_weight[u].emplace_back(weight[u]);
    for (auto v : adj_list[u])
    {
        if (!vis[v])
        {
            dfs(v, adj, vis);
            sub_weight[u].insert(sub_weight[u].end(), sub_weight[v].begin(), sub_weight[v].end());
        }
    }
    sort(sub_weight[u].begin(), sub_weight[u].end(), greater<int>());
    if (sub_weight[u].size() > 20)
        sub_weight[u].resize(20);
}

int main()
{
    ios::sync_with_stdio(), cin.tie(0), cout.tie(0);

    int n, q;
    cin >> n >> q;

    adj_list.resize(n + 5);
    weight.resize(n + 5);
    sub_weight.resize(n + 5);
    visited.resize(n + 5, false);
    for (int i = 1; i <= n; ++i)
    {
        cin >> weight[i];
    }
    for (int i = 0; i < n - 1; ++i)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].emplace_back(b);
        adj_list[b].emplace_back(a);
    }

    dfs(1, adj_list, visited);

    for (int i = 0; i < q; ++i)
    {
        int v, k;
        cin >> v >> k;
        cout << sub_weight[v][k - 1] << "\n";
    }
}