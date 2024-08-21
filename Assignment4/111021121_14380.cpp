#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <climits>
using namespace std;

int n, m, T;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> T;
    while (T--)
    {
        cin >> n >> m;
        vector<vector<int>> G(n + 1);
        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            G[u].emplace_back(v);
        }

        int leng = INT_MAX;
        vector<int> in_stk(n + 1), vis(n + 1), dis(n + 1);
        function<void(int)> dfs_cycle = [&](int u)
        {
            in_stk[u] = 1;
            vis[u] = 1;
            for (int v : G[u])
            {
                if (in_stk[v])
                {
                    leng = min(leng, dis[u] - dis[v] + 1);
                }
                if (!vis[v])
                {
                    dis[v] += dis[u] + 1;
                    dfs_cycle(v);
                }
            }
            in_stk[u] = 0;
        };
        for (int i = 1; i <= n; i++)
        {
            if (!vis[i])
                dfs_cycle(i);
            else
                continue;
        }

        if (leng != INT_MAX)
            cout << leng << '\n';
        else
            cout << -1 << '\n';
    }
}