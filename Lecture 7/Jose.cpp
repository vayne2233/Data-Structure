#include <iostream>
#include <list>
using namespace std;

int main()
{
    ios::sync_with_stdio(), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;

    if ( n == 1 ) 
    {
        cout << 1;
        return 0;
    }

    list<int> Jose;

    for ( int i = 1; i < n + 1; i++ ) Jose.push_back(i);

    auto it = Jose.begin();
    it++;

    for ( int i = 0; i < n; i++ )
    {
        cout << *it;
        if ( i != n - 1 ) cout << " ";

        it = Jose.erase(it);

        if ( it == Jose.end() ) it = Jose.begin();

        it++;

        if ( it == Jose.end() ) it = Jose.begin();
    }
}

