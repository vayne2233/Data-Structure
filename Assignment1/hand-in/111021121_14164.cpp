#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int p, int r)
{
    random_shuffle(arr.begin() + p, arr.begin() + r + 1);
    int i = p;
    for (int j = p; j < r; j++)
    {
        if (arr[j] <= arr[r])
        {
            swap(arr[j], arr[i]);
            i++;
        }
    }
    swap(arr[i], arr[r]);
    return i;
}

int quickselect(vector<int> &arr, int p, int r, int k)
{
    if (p == k)
        return arr[k];

    int q = partition(arr, p, r);
    int i = q - p + 1;
    if (k == i)
        return arr[q];
    else if (k < i)
        quickselect(arr, p, q - 1, k);
    else
        quickselect(arr, q + 1, r, k - i);
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &x : arr)
        cin >> x;

    if (n % 2 == 0)
    {
        cout << (quickselect(arr, 0, n - 1, n / 2) + quickselect(arr, 0, n - 1, n / 2 + 1)) / 2 << "\n";
    }
    else
    {
        cout << quickselect(arr, 0, n - 1, n / 2 + 1) << "\n";
    }
}