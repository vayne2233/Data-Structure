#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL cnt = 0;

void merge(vector<LL> &arr, int l, int m, int r)
{
    vector<LL> tmp;
    int i = l, j = m + 1;

    while (i <= m && j <= r)
    {
        if (arr[i] <= arr[j])
        {
            tmp.emplace_back(arr[i]);
            i++;
        }
        else
        {
            cnt += m + 1 - i;
            tmp.emplace_back(arr[j]);
            j++;
        }
    }
    while (i <= m)
    {
        tmp.emplace_back(arr[i]);
        i++;
    }
    while (j <= r)
    {
        tmp.emplace_back(arr[j]);
        j++;
    }
    for (int k = 0; k < tmp.size(); k++)
    {
        arr[l + k] = tmp[k];
    }
}

void merge_sort(vector<LL> &arr, int l, int r)
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
    vector<LL> arr(n);
    for (auto &x : arr)
        cin >> x;

    merge_sort(arr, 0, n - 1);

    cout << cnt << "\n";
}