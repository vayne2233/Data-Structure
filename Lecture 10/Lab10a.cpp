#include <iostream>
#include <vector>
#include <functional>
using namespace std;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    vector<pair<int, int>> _tree( 1000005 );
    vector<int> parent( 1000005 );
    cin >> n;
    for ( int i = 1; i <= n; i++ )
    {
        cin >> _tree[i].first >> _tree[i].second;
        if ( _tree[i].first != -1 ) parent[_tree[i].first] = i;
        if ( _tree[i].second != -1 ) parent[_tree[i].second] = i;
    }

    vector<int> ans;
    function<void( int )> pre = [&]( int id )
    {
        if ( id == -1 ) return;
        ans.push_back( id );
        pre( _tree[id].first );
        pre( _tree[id].second );
    };

    for ( int i = 1; i <= n; i++ )
    {
        if ( !parent[i] ) pre( i );
    }

    cout << ans.back() << "\n";
}
