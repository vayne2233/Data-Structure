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

void quicksort(vector<int> &arr, int p, int r)
{
    if (p < r)
    {
        int q = partition(arr, p, r);
        quicksort(arr, p, q - 1);
        quicksort(arr, q + 1, r);
    }
}

int binary_search(vector<int> &arr, int n, int val)
{
    int l = 0, r = n - 1, mid;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (arr[mid] == val)
            return mid;
        else if (arr[mid] > val)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return mid;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);

    for (auto &x : arr)
        cin >> x;

    quicksort(arr, 0, n - 1);

    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        if (l > arr[n - 1])
            cout << "0" << "\n";
        else
        {
            cout << upper_bound(arr.begin(), arr.end(), r) - lower_bound(arr.begin(), arr.end(), l) << "\n";
        }
    }
}