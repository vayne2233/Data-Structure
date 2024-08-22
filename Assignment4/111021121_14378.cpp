#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n;
vector<vector<int>> region(310, vector<int>(310));

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
        return 0;
    if (sz[u] > sz[v])
        swap(u, v);
    fa[u] = v;
    sz[v] += sz[u];
    return 1;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> region[i][j];
        }
    }
}