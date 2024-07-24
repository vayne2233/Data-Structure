#include <bits/stdc++.h>
using namespace std;

int partition( vector<int> &arr, int p, int r ) {
    random_shuffle( arr.begin() + p, arr.begin() + r + 1 );
    int i = p;
    for ( int j = p; j < r; j++ ) {
        if ( arr[j] <= arr[r] ) {
            swap( arr[j], arr[i] );
            i++;
        }
    }
    swap( arr[i], arr[r] );
    return i;
}

void quicksort( vector<int> &arr, int p, int r ) {
    if ( p < r ) {
        int q = partition( arr, p, r );
        quicksort( arr, p, q - 1 );
        quicksort( arr, q + 1, r );
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<int> arr( n );
    for ( auto &x : arr ) cin >> x;

    quicksort( arr, 0, n - 1);

    for ( auto &x : arr) cout << x << " ";
    cout << "\n";
}