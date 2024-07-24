#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(), cin.tie(0), cout.tie(0);
    long long n, q, V;
    cin >> n >> q >> V;
    long long max = -1;
    vector<long long> arr;

    arr.emplace_back(V);

    for (int i = 0; i < n; i++)
    {
        long long x, v;
        cin >> x >> v;
        if (x <= arr[arr.size() - 1])
        {
            max = v + arr[arr.size() - 1];
            arr.emplace_back(max);
        }
        else
        {
            continue;
        }
    }

    for (int i = 0; i < q; i++)
    {
        long long x;
        cin >> x;
        if (max < x)
            cout << -1 << "\n";
        else
            cout << lower_bound(arr.begin(), arr.end(), x) - arr.begin() << "\n";
    }
}