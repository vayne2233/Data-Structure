#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int bfs( int n, vector<vector<int>> &arr, vector<int> &cookie, int st )
{
    queue<int> q;
    vector<int> dis(n, -1);
    vector<int> in(n);
    for ( int i : cookie ) in[i] = 1;
    dis[st] = 0;
    q.push(st);
    while ( !q.empty() )
    {


int main()
{
    int t;
    cin >> t;
    while ( t-- )
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj_list(n);
        for ( int i = 0; i < m; i++ )
        {
            int u, v;
            cin >> u >> v;
            u--, v--;
            adj_list[u].emplace_back(v);
            adj_list[v].emplace_back(u);
        }
        int s, sz;
        vector<int> cookie;
        cin >> s;
        cin >> sz;
        while ( sz-- )
        {
            int x;
            cin >> x;
            x--;
            cookie.emplace_back(x);
        }
        int res = bfs( n, adj_list, cookie, s - 1 );
        if ( res == -1 ) cout << "SAD\n";
        else cout << res << "\n";
    }
}
