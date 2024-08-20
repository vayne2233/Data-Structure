#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

const int N = 1e5 ;
int vis1[N], vis2[N];
int n, m;
long long dis[N];
vector<int> G[N], rG[N];
vector< pair< pair<int, int>, int > > E;

void dfs( vector<int> arr[], int vis[], int u )
{
    vis[u] = 1;
    for ( auto v: arr[u] )
    {
        if ( !vis[v] )
            dfs( arr, vis, v );
    }
}

long long bellman( int root )
{
    for ( int i = 1; i <= n; i++ )
    {
        dis[i] = 1e18;
    }
    dis[root] = 0;

    for ( int i = 1; i <= n; i++ )
    {
        for ( auto e: E )
        {
            int u = e.first.first;
            int v = e.first.second;
            int w = e.second;

            if ( !vis1[u] || !vis2[v] ) continue;

            if ( dis[u] + w < dis[v] )
            {
                if ( i == n )
                {
                    return 1;
                }
                dis[v] = dis[u] + w;
            }
        }
    }

    return dis[n];
}

int main()
{
    cin >> n >> m;
    for ( int i = 0; i < m; i++ )
    {
        int a, b, x;
        cin >> a >> b >> x;
        G[a].emplace_back( b );
        rG[b].emplace_back( a );
        E.emplace_back( make_pair( make_pair( a, b ), -x ) );
    }

    dfs( G, vis1, 1 );
    dfs( rG, vis2, n );

    cout << -bellman( 1 ) << "\n";
}
