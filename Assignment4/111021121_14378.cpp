#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
#include <queue>
using namespace std;

int n, path, max_weight = 0;
vector<int> region(90010);

vector<tuple<int, int, int>> E;

struct DSU
{
    int n;
    vector<int> fa, sz;
    DSU(int n)
    {
        fa.resize(n + 1);
        sz.resize(n + 1, 1);
        for (int i = 1; i <= n; i++)
        {
            fa[i] = i;
        }
    }

    int find(int x);
    bool unite(int u, int v);
};

int DSU::find(int x)
{
    return (fa[x] == x ? fa[x] : fa[x] = find(fa[x]));
}

bool DSU::unite(int u, int v)
{
    u = find(u), v = find(v);
    if (u == v)
        return false;
    if (sz[u] > sz[v])
        swap(u, v);
    fa[u] = v;
    sz[v] += sz[u];
    return true;
}

void bfs(int start, vector<vector<pair<int, int>>> &G, vector<bool> &vis)
{
    queue<int> q;
    queue<int> dist;
    vis[start] = true;
    q.push(start);
    dist.push(0);
    while (!q.empty())
    {
        int u = q.front();
        int cnt = dist.front();
        q.pop();
        dist.pop();
        for (auto v : G[u])
        {
            if (vis[v.first])
                continue;
            if (v.second > max_weight)
                continue;
            if (v.first == n * n)
            {
                path = cnt + 1;
                return;
            }
            vis[v.first] = true;
            q.push(v.first);
            dist.push(cnt + 1);
        }
    }
    return;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    vector<vector<pair<int, int>>> G(n * n + 1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> region[n * (i - 1) + j];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == 1 && j == 1)
                continue;
            else if (i == 1)
            {
                int pre, now;
                now = n * (i - 1) + j;
                pre = n * (i - 1) + j - 1;
                E.emplace_back(make_tuple(pre, now, abs(region[now] - region[pre])));
                G[now].emplace_back(make_pair(pre, abs(region[now] - region[pre])));
                G[pre].emplace_back(make_pair(now, abs(region[now] - region[pre])));
            }
            else if (j == 1)
            {
                int now, above;
                now = n * (i - 1) + j;
                above = n * (i - 2) + j;
                E.emplace_back(make_tuple(above, now, abs(region[now] - region[above])));
                G[now].emplace_back(make_pair(above, abs(region[now] - region[above])));
                G[above].emplace_back(make_pair(now, abs(region[now] - region[above])));
            }
            else
            {
                int now, pre, above;
                now = n * (i - 1) + j;
                pre = n * (i - 1) + j - 1;
                above = n * (i - 2) + j;
                E.emplace_back(make_tuple(above, now, abs(region[now] - region[above])));
                E.emplace_back(make_tuple(pre, now, abs(region[now] - region[pre])));
                G[now].emplace_back(make_pair(pre, abs(region[now] - region[pre])));
                G[pre].emplace_back(make_pair(now, abs(region[now] - region[pre])));
                G[now].emplace_back(make_pair(above, abs(region[now] - region[above])));
                G[above].emplace_back(make_pair(now, abs(region[now] - region[above])));
            }
        }
    }

    sort(E.begin(), E.end(), [](auto &a, auto &b)
         { return get<2>(a) < get<2>(b); });

    DSU dsu(n * n);

    for (auto &[u, v, w] : E)
    {
        if (dsu.unite(u, v))
        {
            if (dsu.find(1) == dsu.find(n * n))
            {
                max_weight = w;
                break;
            }
        }
    }

    cout << max_weight << '\n';

    vector<bool> vis(n * n + 1, false);

    bfs(1, G, vis);

    cout << path << '\n';
}