#include <iostream>
#include <algorithm>
using namespace std;

int n, m, q;
const int N = 1e3;
long long dis[N][N];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m >> q;

    for ( int i = 1; i <= n; i++ )
    {
        for ( int j = 1; j <= n; j++ )
        {
            dis[i][j] = ( i == j ? 0 : 1e18 );
        }
    }

    while ( m-- )
    {
        long long a, b, c;
        cin >> a >> b >> c;
        dis[a][b] = min( dis[a][b], c );
        dis[b][a] = min( dis[b][a], c );
    }

    for ( int k = 1; k <= n; k++ )
    {
        for ( int i = 1; i <= n; i++ )
        {
            for ( int j = 1; j <= n; j++ )
            {
                dis[i][j] = min( dis[i][j], dis[i][k] + dis[k][j] );
            }
        }
    }

    while ( q-- )
    {
        int u, v;
        cin >> u >> v;
        cout << ( dis[u][v] >= 1e18 ? -1 : dis[u][v] ) << "\n";
    }
}
