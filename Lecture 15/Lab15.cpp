#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
using namespace std;

const int N = 1e5 + 5;
long long x[N], y[N];
long long dis[N];
bitset<N> vis;

long long cal( long long x1, long long y1, long long x2, long long y2)
{
    return ( x1 - x2 ) * ( x1 - x2 ) + ( y1 - y2 ) * ( y1 - y2 );
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for ( int i = 0; i < n; i++ )
    {
        cin >> x[i] >> y[i];
        dis[i] = 1e10;
    }

    long long mn, now = 0, nex = 0, ans = 0;
    vis[now] = 1;
    for ( int rd = 0; rd < n - 1; rd++ )
    {
        mn = -1;
        for ( int i = 0; i < n; i++ )
        {
            if ( vis[i] ) continue;
            dis[i] = min( dis[i], cal( x[now], y[now], x[i], y[i] ) );
            if ( mn == -1 || mn > dis[i] )
            {
                mn = dis[i];
                nex = i;
            }
        }
        vis[nex] = 1;
        ans += dis[nex];
        now = nex;
    }
    cout << ans << "\n";
}
        
