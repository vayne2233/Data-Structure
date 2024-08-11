#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ordered_set<int> ord_s;
    int q, x;
    cin >> q;
    for ( int i = 0; i < q; ++i )
    {
        string s;
        cin >> s >> x;
        if ( s == "INS" )
            ord_s.insert(x);
        else if ( s == "DEL" )
        {
            if ( ord_s.find(x) != ord_s.end() ) 
                ord_s.erase(x);
        }
        else if ( s == "ORD")
        {
            if ( ord_s.find(x) != ord_s.end() )
            {
                cout << ord_s.order_of_key(x) + 1;
            }
            else cout << ord_s.order_of_key(x);
            cout << "\n";
        }
    }
}
