#include <iostream>
#include <climits>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int N = 505;
int n, m, T;

int main()
{
    cin >> T;
    while ( T-- )
    {
        cin >> n >> m;
        vector< vector<int> > adj_list(N);
        vector<bool> vis(N, false);
        for ( int i = 0; i < m; i++ )
        {
            int u, v;
            cin >> u >> v;
            G[u].emplace_back( v );
        }

        int ans = INT_MAX;

        for ( int i = 1; i <= n; i++ )
        {
            vector<int> dis( n, 1e9 );
            dis[i] = 0;
            queue<int> q;

            q.push(i);

            while ( !q.empty() )
            {
                int x = q.front();
                q.pop();

                for ( auto v: G[x] )
                {
                    if ( dis[v] == 1e9 )
                    {
                        dis[v] = 1 + dis[x];

                        vis[v] = true;

                        q.push( v );
                    }
                    else if ( par
        }

