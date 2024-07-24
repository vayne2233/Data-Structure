#include <bits/stdc++.h>
using namespace std;

stack<int> st;
queue<int> a;
queue<int> b;

int main()
{
    int n;
    cin >> n;
    for ( int i = 0; i < n; i++ )
    {
        int b_i;
        cin >> b_i;
        b.push( b_i );
        a.push( i + 1 );
    }

    for ( int i = 0; i < 2 * n; i++ )
    {
        if ( !st.empty() )
        {
            if ( b.front() == st.top() )
            {
                cout << "Pop\n";
                b.pop();
                st.pop();
            }
            else
            {
                cout << "Push\n";
                st.push( a.front() );
                a.pop();
            }
        }
        else
        {
            st.push( a.front() );
            a.pop();
            cout << "Push\n";
        }
    }
}
