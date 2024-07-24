#include <iostream>
#include <list>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(), cin.tie(0), cout.tie(0);
    int n;
    string str;
    list<int> mylist;
    mylist.emplace_back(0);

    cin >> n;
    cin >> str;

    auto it = mylist.begin();

    for ( int i = 0; i < n; i++ ) 
    {
        if ( str[i] == 'L' )
        {
            mylist.insert(it, i + 1);
            --it;
        }
        else
        {
            if ( it == mylist.end() ) mylist.emplace_back(i+1);
            else
            {
                it++;
                mylist.insert(it, i + 1);
                it--;
            }
        }
    }

    int cnt = 0;
    for ( auto it = mylist.begin(); it != mylist.end(); it++ )
    {
        cout << *it;
        cnt += 1;
        if ( cnt != mylist.size() ) cout << " ";
    }
    cout << "\n";
}
