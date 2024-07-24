#include "bits/stdc++.h"
using namespace std;
typedef long long LL;

int binary_search(vector<LL> &arr, int n, LL val) {
    int l = 0, r = n - 1, mid;
    while (l <= r) {
        mid = (l + r) / 2;
        if(arr[mid] == val) return mid;
        else if(arr[mid] > val) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<LL> num(n);
    for (auto &x : num)
        cin >> x;
    LL q;
    while (m--) {
        cin >> q;
        if(binary_search(num, n, q) >= 0)
            cout << "Y ";
        else
            cout << "N ";
    }
}
