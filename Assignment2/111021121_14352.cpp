#include <iostream>
#include <string>
using namespace std;

const int N = 1e6 + 10;
const long long X = 37, M = 1e9 + 7;

long long int pw[N];
long long int Hash[N], arr[N / 2];

int main()
{
    ios::sync_with_stdio(), cin.tie(0), cout.tie(0);
    string s;
    cin >> s;
    if (s.length() == 1)
    {
        cout << 0 << " " << "\n";
        return 0;
    }

    pw[0] = 1;
    for (int i = 1; i < s.length(); i++)
        pw[i] = pw[i - 1] * X % M;

    Hash[0] = s[0];

    for (int j = 1; j < s.length(); j++)
    {
        Hash[j] = (Hash[j - 1] * X + s[j] % M) % M;
    }

    int j = 0;

    for (int i = 0; i < s.length() - 1; i++)
    {
        long long int a = Hash[s.length() - i - 2] * pw[i + 1] % M;
        long long int y = Hash[s.length() - 1] - a;
        if (y < 0)
            y = (y + M) % M;
        if (Hash[i] == y)
        {
            cout << i + 1 << " ";
        }
    }

    cout << "\n";
}