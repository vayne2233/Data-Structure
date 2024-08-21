#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

vector<tuple<int, int, int>> in_MST;

struct DSU
{
    vector<int> fa, sz;
    DSU(int n)
    {
        fa.resize(n + 1);
        sz.resize(n + 1, 1);
        for (int i = 0; i <= n; i++)
            fa[i] = i;
    }
    int find(int x)
    {
        return (fa[x] == x ? x : fa[x] = find(fa[x]));
    }
    bool unite(int a, int b)
    {
        a = find(a), b = find(b);
        if (a == b)
            return 0;
        if (sz[a] > sz[b])
            swap(a, b);
        fa[a] = b;
        sz[b] += sz[a];
        return 1;
    }
};

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    DSU dsu(n);
    vector<tuple<int, int, int>> edges(m);
    for (auto &[u, v, w] : edges)
        cin >> u >> v >> w;
    sort(edges.begin(), edges.end(), [](auto &a, auto &b)
         { return get<2>(a) < get<2>(b); });
    for (auto &[u, v, w] : edges)
    {
        if (dsu.unite(u, v))
            in_MST.emplace_back(make_tuple(u, v, w));
    }

    long long ans = 1e18;

    for (auto &[a, b, c] : in_MST)
    {
        int t = 1;
        long long g = 0;
        DSU dsu(n);
        for (auto &[u, v, w] : edges)
        {
            if (a == u && b == v && c == w)
                continue;
            if (dsu.unite(u, v))
            {
                t++;
                g += w;
            }
        }
        if (t == n)
            ans = min(g, ans);
    }
    cout << ans << '\n';
}