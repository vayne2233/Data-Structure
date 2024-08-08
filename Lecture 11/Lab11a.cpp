#include <iostream>
#include <set>
using namespace std;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, x;
    cin >> n;
    string op;
    set<int> s;
    while ( n-- )
    {
        cin >> op >> x;
        switch ( op[0] )
        {
            case 'I':
                if ( s.find(x) == s.end() ) s.insert(x);
                cout << s.size() << "\n";
                break;
            case 'D':
                if ( s.find(x) != s.end() ) s.erase(x);
                cout << s.size() << "\n";
                break;
            case 'S':
                if ( s.find(x) != s.end() ) cout << "YES";
                else cout << "NO";
                cout << "\n";
                break;
            case 'L':
                if ( s.lower_bound(x) != s.end() ) cout << *s.lower_bound(x) << "\n";
                else cout << "-1" << "\n";
                break;
            case 'U':
                if ( s.upper_bound(x) != s.end() ) cout << *s.upper_bound(x) << "\n";
                else cout << "-1" << "\n";
                break;
        }
    }
}
    
