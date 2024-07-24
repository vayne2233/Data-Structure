#include <bits/stdc++.h>
using namespace std;

bool check1(vector<pair<int, int>> &pts, int n, int k, int m)
{
    priority_queue<int> pq;

    for (int i = 0; i < k - 1; i++)
        pq.push(pts[i].second);

    for (int i = k - 1; i < n; i++)
    {
        pq.push(pts[i].second);

        if (pts[i].second > m - pts[i].first)
            continue;

        while (pq.size() >= k)
        {
            if (pq.top() <= m - pts[i].first)
            {
                return true;
            }
            else
                pq.pop();
        }
    }
    return false;
}

bool check2(vector<pair<int, int>> &pts, int n, int k, int m)
{
    priority_queue<int> pq;

    for (int i = 0; i < k - 1; i++)
        pq.push(pts[i].second);

    for (int i = k - 1; i < n; i++)
    {
        pq.push(pts[i].second);

        if (pts[i].second > m - pts[i].first)
            continue;

        while (pq.size() >= k)
        {
            if (pq.top() == m - pts[i].first)
            {
                return true;
            }
            else
            {
                pq.pop();
            }
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> pts(n);

    int x_max = -1;
    int y_max = -1;
    int x_min = 1e6;
    int y_min = 1e6;

    for (auto &x : pts)
    {
        cin >> x.first >> x.second;
        x_max = max(x_max, x.first);
        y_max = max(y_max, x.second);
        x_min = min(x_min, x.first);
        y_min = min(y_min, x.second);
    }

    sort(pts.begin(), pts.end());

    int l = x_min + y_min;
    int r = x_max + y_max;

    while (l + 1 != r)
    {
        int m = (l + r) / 2;
        if (check1(pts, n, k, m))
            r = m;
        else
            l = m + 1;
    }

    int ans = l;

    while (1)
    {
        if (check2(pts, n, k, ans))
        {
            break;
        }
        ans++;
    }
    cout << ans << "\n";
}