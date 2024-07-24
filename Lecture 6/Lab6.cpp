#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct DSU
{
    int cnt, max_size;
    vector<int> parent, size;

    DSU( int n )
    {
        parent.resize( n + 1 ), size.resize( n + 1 );
        for ( int i = 1; i <= n; i++ ) parent[i] = i, size[i] = 1;
        cnt = n, max_size = 1;
    };

    int find_root( int u );
    bool unite( int u, int v);
};

int DSU::find_root( int u )
{
    return (u == parent[u] ? u : parent[u] = find_root( parent[u] ));
}

bool DSU::unite( int u, int v )
{
    u = find_root( u ), v = find_root( v );
    if ( u == v ) return false;
    if ( size[u] < size[v] ) swap( u, v );
    size[u] += size[v];
    parent[v] = u;
    cnt--;
    max_size = max( size[u], max_size );
    return true;
}

int main()
{
    int n, m;
    cin >> n >> m;
    DSU MyDSU(n);
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        MyDSU.unite( u, v );
        cout << MyDSU.cnt << " " << MyDSU.max_size << "\n";
    }
}
