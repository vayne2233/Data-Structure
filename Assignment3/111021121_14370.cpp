#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.first > b.first;
}

int cnt = 0;

void kill(vector<pair<int, int>> &arr, int h)
{
    for (int i = 0; i < arr.size(); ++i)
    {
        if (arr[i].second >= h)
        {
            cnt += 1;
            h -= arr[i].first;
            if (h <= 0)
            {
                cout << cnt;
                return;
            }
            else
            {
                arr.erase(arr.begin() + i);
                kill(arr, h);
                return;
            }
        }
    }
    cout << -1;
    return;
}

int main()
{
    bool killed = false;
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> loli(n);
    for (int i = 0; i < n; i++)
    {
        cin >> loli[i].first >> loli[i].second;
    }

    sort(loli.begin(), loli.end(), cmp);

    kill(loli, m);
    cout << "\n";
}
