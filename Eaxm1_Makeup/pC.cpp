#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL cnt = 0;

void merge(vector<pair<int, int>> &arr, int l, int m, int r)
{
    vector<pair<int, int>> tmp;
    int i = l, j = m + 1;

    while (i <= m && j <= r)
    {
        if (arr[i].second <= arr[j].second )
        {
            cnt += r + 1 - j;
            tmp.emplace_back( make_pair( arr[i].first, arr[i].second ) );
            i++;
        }
        else
        {
            tmp.emplace_back( make_pair( arr[j].first, arr[j].second ) );
            j++;
        }
    }
    while (i <= m)
    {
        tmp.emplace_back( make_pair( arr[i].first, arr[i].second ) );
        i++;
    }
    while (j <= r)
    {
        tmp.emplace_back( make_pair( arr[j].first, arr[j].second ) );
        j++;
    }
    for (int k = 0; k < tmp.size(); k++)
    {
        arr[l + k] = tmp[k];
    }
}

void merge_sort(vector<pair<int, int>> &arr, int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> pts(n);
    for (auto &x : pts )
    {
        int u, r;
        cin >> u >> r;
        x.first = min(u, r);
        x.second = max(u, r);
    }    

    sort( pts.begin(), pts.end() );

    merge_sort(pts, 0, n - 1);

    cout << cnt << "\n"; 
}
