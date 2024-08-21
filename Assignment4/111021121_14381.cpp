#include <iostream>
#include <vector>
using namespace std;

int n, m;

struct DSU
{
    int n;
    vector<int> pa, sz;

    DSU(int n)
    {
        pa.resize(n + 1), sz.resize(n + 1);
        for ( int i = 1; i <= n; i++ ) pa[i] = i;
    };

    int find_pa( int u );
    bool uni( int u, int v );
};

int DSU::find_pa( int u )
{
    return (pa[u] == u ? u : pa[u] = find_pa(u));
}

bool DSU::uni( int u, int v )
{
    int a = find_pa(u), b = find_pa(v);
    if ( a == b ) return 0;
    if ( sz[a] > sz[b] ) swap(a, b);
    pa[a] = b;
    sz[b] += sz[a];
    return 1;
}

int main()
{
    cin >> n >> m;
    while ( m-- )
    {
        int u, v, c;
        cin >> u >> v >> c;

    }
}