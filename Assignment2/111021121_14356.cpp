#include <bits/stdc++.h>
using namespace std;

stack<pair<int, int>> op;
stack<pair<int, int>> ans;

vector<int> sz;
vector<int> parent;

int max_size = 0, cnt = 0;

int find_root(int x)
{
    return (x == parent[x] ? x : parent[x] = find_root(parent[x]));
}

void unite(int x, int y)
{
    int rx = find_root(x), ry = find_root(y);
    if (rx == ry)
        return;
    cnt--;
    if (sz[rx] < sz[ry])
        swap(rx, ry);
    parent[ry] = rx;
    sz[rx] += sz[ry];
    max_size = max(max_size, sz[rx]);
    return;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> row(m + 2, 0);
    vector<vector<int>> arr(n + 2, row);
    parent.resize(n * m + 1);
    sz.resize(n * m + 1);

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            parent[m * (i - 1) + j] = m * (i - 1) + j;
            sz[m * (i - 1) + j] = 1;
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
        arr[x][y] = 0;
        op.push(make_pair(x, y));
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (arr[i][j])
            {
                cnt++;
                if (arr[i - 1][j] == 0 && arr[i][j - 1] == 0)
                    max_size = 1;
                if (arr[i - 1][j] == 1 && arr[i][j - 1] == 0)
                    unite(m * (i - 2) + j, m * (i - 1) + j);
                else if (arr[i][j - 1] == 1 && arr[i - 1][j] == 0)
                    unite(m * (i - 1) + j - 1, m * (i - 1) + j);
                else if (arr[i - 1][j] == 1 && arr[i][j - 1] == 1)
                {
                    unite(m * (i - 2) + j, m * (i - 1) + j);
                    unite(m * (i - 1) + j - 1, m * (i - 1) + j);
                }
            }
        }
    }

    ans.push(make_pair(max_size, cnt));

    for (int i = 0; i < k; i++)
    {
        int u = op.top().first, v = op.top().second;
        op.pop();
        arr[u][v] = 1;
        cnt++;
        if (max_size < 1)
            max_size = 1;
        if (arr[u - 1][v])
            unite(m * (u - 2) + v, m * (u - 1) + v);
        if (arr[u][v - 1])
            unite(m * (u - 1) + v - 1, m * (u - 1) + v);
        if (arr[u][v + 1])
            unite(m * (u - 1) + v + 1, m * (u - 1) + v);
        if (arr[u + 1][v])
            unite(m * u + v, m * (u - 1) + v);
        ans.push(make_pair(max_size, cnt));
    }

    for (int i = 0; i < k + 1; i++)
    {
        cout << ans.top().first << " " << ans.top().second << "\n";
        ans.pop();
    }
    return 0;
}
