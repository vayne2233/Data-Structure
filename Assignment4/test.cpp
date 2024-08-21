#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> g(n + 1);

        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            g[a].push_back(b);
        }

        vector<int> dist(n + 1);
        int current = 0;
        int ringSize = INT_MAX;

        function<void(int node)> dfs = [&](int node)
        {
            if (dist[node] != 0)
            {
                ringSize = min(ringSize, current - dist[node] + 1);
                return;
            }
            current += 1;
            dist[node] = current;
            for (int i = 0; i < g[node].size(); i++)
            {
                dfs(g[node][i]);
            }
            dist[node] = 0;
            current -= 1;
        };
        dfs(1);
        if (ringSize == INT_MAX) cout << -1 << '\n';
        else cout << ringSize << endl;
    }
}