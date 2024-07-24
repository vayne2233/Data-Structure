#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for ( int i = 0; i < q; i++ ) {
        int type;
        cin >> type;
        if ( type == 1) {
            int elem;
            cin >> elem;
            pq.push(elem);
        }
        if ( type == 2) {
            if ( pq.empty() ) continue;
            pq.pop();
        }
        if ( type == 3 ) {
            if ( pq.empty() ) cout << "EMPTY\n";
            else cout << pq.top() << "\n";
        }
    }
}