#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int bfs(int n, const vector<vector<int>> &adj, vector<int> &ed, int st)
{
    queue<int> q;
    vector<int> dis(n, -1);
    vector<int> in(n);
    for (int i : ed)
        in[i] = 1;
    dis[st] = 0;
    q.push(st);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        if (in[u])
            return dis[u];
        for (int v : adj[u])
        {
            if (dis[v] == -1)
            {
                dis[v] = dis[u] + 1;
                q.push(v);
            }
        }
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj_list(n);
        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            u--, v--;
            adj_list[u].emplace_back(v);
            adj_list[v].emplace_back(u);
        }
        int s, sz;
        vector<int> cookie;
        cin >> s;
        cin >> sz;
        while (sz--)
        {
            int x;
            cin >> x;
            x--;
            cookie.emplace_back(x);
        }
        int res = bfs(n, adj_list, cookie, s - 1);
        if (res == -1)
            cout << "SAD\n";
        else
            cout << res << "\n";
    }
}
