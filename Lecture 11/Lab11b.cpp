#include <iostream>
#include <map>
using namespace std;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, x;
    cin >> n;
    char op;
    map<int, int> mp;
    while ( n-- )
    {
        cin >> op >> x;
        switch( op )
        {
            case 'I':
                mp[x]++;
                cout << mp.size() << "\n";
                break;
            case 'D': 
                if ( mp.find(x) != mp.end() )
                {
                    mp[x]--;
                    if ( mp[x] == 0 ) mp.erase(x);
                }
                cout << mp.size() << "\n";
                break;
            case 'C':
                if ( mp.find(x) != mp.end() ) cout << mp[x];
                else cout << "0";
                cout << "\n";
                break;
            case 'L':
                if ( mp.lower_bound(x) != mp.end() )
                    cout << (*mp.lower_bound(x)).first << "\n";
                else cout << "-1\n";
                break;
            case 'U':
                if ( mp.upper_bound(x) != mp.end() )
                    cout << (*mp.upper_bound(x)).first << "\n";
                else cout << "-1\n";
                break;
        }
    }
}


