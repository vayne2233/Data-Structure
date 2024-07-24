#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void merge(vector<LL> &arr, int L, int M, int R)
{
    vector<LL> tmp;
    int i = L, j = M;
    while (i != M && j != R)
    {
        if (arr[i] > arr[j])
        {
            tmp.push_back(arr[i]);
            i += 1;
        }
        else
        {
            tmp.push_back(arr[j]);
            j += 1;
        }
    }
    while (i != M)
    {
        tmp.push_back(arr[i]);
        i += 1;
    }
    while (j != R)
    {
        tmp.push_back(arr[j]);
        j += 1;
    }
    for (int k = L; k < R; k++)
    {
        arr[k] = tmp[k - L];
    }
}

void merge_sort(vector<LL> &arr, int L, int R)
{
    if (L + 1 >= R)
        return;
    else
    {
        int M = (R + L) / 2;
        merge_sort(arr, L, M);
        merge_sort(arr, M, R);
        merge(arr, L, M, R);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<LL> arr(n);
    for (auto &x : arr)
        cin >> x;
    merge_sort(arr, 0, n);

    for (auto &x : arr)
        cout << x << " ";
    cout << "\n";
}