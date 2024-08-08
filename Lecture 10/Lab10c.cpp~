#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <stack>
using namespace std;

string shuntingyardalgo( string s )
{
	map<char, int> priority {
		{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}
	};
	stack<char> op;
	string post;
	for ( auto i : s )
	{
		if ( i >= 'A' && i <= 'E' ) post.push_back( i );
		else if ( i == '+' || i == '-' || i == '*' || i == '/' )
		{
			while ( op.size() && priority[op.top()] >= priority[i] && op.top() != '(' )
			{
				post.push_back(op.top());
				op.pop();
			}
			op.push(i);
		}
		else if ( i == '(' ) op.push( i );
		else if ( i == ')' ) 
		{
			while ( op.top() != '(' )
			{
				post.push_back( op.top() );
				op.pop();
			}
			op.pop();
		}
	}

	while ( op.size() )
	{
		post.push_back( op.top() );
		op.pop();
	}

	return post;
}

void solve( const string &post, int t )
{
	vector<int> val( 5 );
	for ( int i = 0; i < 5; i++ ) cin >> val[i];
	stack<int> st;
	for ( auto s : post )
	{
		if ( s >= 'A' && s <= 'E' ) st.push( val[ s - 'A' ] );
		else 
		{
			int a = st.top();
			st.pop();
			int b = st.top();
			st.pop();
			swap(a, b);
			int ans; 
			if ( s == '+' ) ans = a + b;
			else if ( s == '-') ans = a - b;
			else if ( s == '*') ans = a * b;
			else ans = a / b;
			st.push( ans );
		}
	}
	cout << st.top();
	if ( t ) cout << "\n";
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    string s;
    cin >> s;
	string post = shuntingyardalgo( s );
	int t;
	cin >> t;
	while ( t-- ) solve( post, t );
}
	


