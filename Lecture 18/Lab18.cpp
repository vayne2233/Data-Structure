#include <iostream>
#include <vector>
using namespace std;

const int N = 1e5 + 5;
int n, m, a[N], state[N], dp[N];
vector<int> G[N];

int f( int u )
{
    if ( state[u] == -1 ) return -1;
    if ( state[u] == 0 ) 
    {
        state[u] = -1;
        dp[u] = a[u];
        for ( auto v: G[u] )
        {
            int ans = f( v );
            if ( ans < 0 ) return -1;
            dp[u] += ans;
        }
        state[u] = 1;
    }
    return dp[u];
}

int main()
{
    cin >> n >> m;

    while ( m-- )
    {
        char op;
        int u, v;
        cin >> op >> u;
        for ( int i = 'A'; i < op; i++ )
        {
            cin >> v;
            G[u].emplace_back( v );
        }
        cin >> a[u];
    }

    for ( int i = 1; i <= n; i++ )
    {
        int ans = f( i );
        if ( ans < 0 ) cout << "#REF!\n";
        else cout << ans << '\n';
    }
}
