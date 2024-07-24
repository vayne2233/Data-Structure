#include <bits/stdc++.h>
using namespace std;

const int N = 110;
const int MAXLEN = 5010;
const long long X = 37, M = 1e9 + 7;

int n, q;

long long pw[MAXLEN];
long long Hash[N], len[N];

int main()
{
    ios::sync_with_stdio(), cin.tie(0), cout.tie(0);
    pw[0] = 1;
    for ( int i = 1; i < MAXLEN; i++ )
        pw[i] = pw[i - 1] * X % M;

    cin >> n >> q;

    for ( int i = 0; i < n; i++ )
    {
        string s;
        cin >> s;
        len[i] = s.size();
        for ( int j = 0; j < len[i]; j++ )
            Hash[i] = ( Hash[i] + s[j] * pw[j] % M ) % M;
    }

    while ( q-- )
    {
        char c;
        int x, y;
        cin >> c >> x >> y;
        x--, y--;
        if ( c == 'E' )
        {
            cout << ( Hash[x] == Hash[y] ? "Y" : "N" ) << "\n";
        }
        else
        {
            Hash[x] = ( Hash[x] + Hash[y] * pw[len[x]] % M ) % M;
            len[x] += len[y];
        }
    }
}
