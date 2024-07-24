#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        stack<char> st;
        string str;
        bool ok = true;
        cin >> str;

        for (char x : str)
        {
            if (x == '(' || x == '[')
                st.push(x);
            else
            {
                if (st.empty())
                {
                    ok = false;
                    break;
                }
                else if (x == ')' && st.top() == '(')
                    st.pop();
                else if (x == ']' && st.top() == '[')
                    st.pop();
                else
                    st.push(x);
            }
        }
        if (st.empty() && ok)
            cout << "Y";
        else
            cout << "N";
        if (n > 0)
            cout << "\n";
    }
}