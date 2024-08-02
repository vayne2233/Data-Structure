#include <iostream>
using namespace std; 

const int N = 1e3 + 10;

int n;
int G[N][N];

int main()
{
    int m;
    cin >> n >> m;
    for ( int i = 0; i < m; i++ )
    {
        int u, v;
        cin >> u >> v;
        G[u][v] = 1;
        G[v][u] = 1;
    }

    for ( int i = 1; i <= n; i++ )
    {
        for ( int j = i + 1; j <= n; j++ )
        {
            if ( G[i][j] == 0 )
                cout << i << " " << j << "\n";
        }
    }
}



