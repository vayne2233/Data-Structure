#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> G(n + 1);
    vector<int> in_degree(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        in_degree[v]++;
        G[u].emplace_back(v);
    }

    vector<int> dis(n + 1, 0);

    dis[1] = 1;

    function<void()> topological_sort = [&]()
    {
        queue<int> q;
        for (int i = 1; i <= n; i++)
        {
            if (in_degree[i] == 0)
                q.push(i);
        }
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (int v : G[u])
            {
                dis[v] = ((dis[u] % (1000000007)) + ((dis[v] % (1000000007)))) % (1000000007);
                in_degree[v]--;
                if (in_degree[v] == 0)
                {
                    q.push(v);
                }
            }
        }
    };

    topological_sort();
    cout << dis[n] << endl;
}