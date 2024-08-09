#include <iostream>
#include <algorithm>
using namespace std;

struct node
{
    int key, bf, h, sz;
    node *l, *r, *pa;

    void update();

    node(){}
    node( int _key ) : key(_key), bf(0), h(0), sz(1), pa(NULL), l(NULL), r(NULL) {}
} *root;

void node::update()
{
    int lh = ( l ? l -> h: -1 );
    int rh = ( r ? r -> h: -1 );
    int lsz = ( l ? l -> sz : 0 );
    int rsz = ( r ? r -> sz : 0 );
    sz = lsz + rsz + 1;
    h = max( lh, rh ) + 1;
    bf = lh - rh;
}

node *find_min( node *x )
{
    while ( x -> l ) x = x -> l;
    return x;
}

void trans( node *x, node *y )
{
    if ( !x -> pa ) root = y;
    else if ( x -> pa -> l == x ) x -> pa -> l = y;
    else x -> pa -> r = y;
    if ( y ) y -> pa = x -> pa;
}

void rrot( node *x )
{
    node *left_child = x -> l;
    trans( x, left_child );

    x -> l = left_child -> r;
    if ( left_child -> r ) left_child -> r -> pa = x;

    left_child -> r = x;
    x -> pa = left_child;

    x -> update();
    left_child -> update();
}

void lrot( node *x )
{
    node *right_child = x -> r;
    trans( x, right_child );

    x -> r = right_child -> l;
    if ( right_child -> l ) right_child -> l -> pa = x;

    right_child -> l = x;
    x -> pa = right_child;

    x -> update();
    right_child -> update();
}

void insert( node *&x, node *z )
{
    if ( x == NULL )
    {
        x = z;
        return;
    }

    if ( z -> key == x -> key ) return;

    if ( x -> key < z -> key )
    {
        if ( x -> r ) insert( x -> r, z );
        else x -> r = z, z -> pa = x;
    }

    else 
    {
        if ( x -> l ) insert( x -> l, z );
        else x -> l = z, z -> pa = x;
    }

    x -> update();

    if ( x -> bf == 2 )
    {
        if ( x -> l -> bf == 1 ) rrot( x );
        else if ( x -> l -> bf == -1 ) lrot( x -> l ), rrot( x );
    }

    else if ( x -> bf == -2 )
    {
        if ( x -> r -> bf == -1 ) lrot( x );
        else if ( x -> r -> bf == 1 ) rrot( x -> r ), lrot( x );
    }
}

void del( node *x, int key )
{
    if ( x == NULL ) return;

    if ( key < x -> key ) del( x -> l, key );
    else if ( key > x -> key ) del( x -> r, key );
    else
    {
        if ( !( x -> l) && !( x -> r) )
        {
            trans( x, NULL );
            return;
        }
        else if ( !( x -> l ) ) trans( x, x -> r );
        else if ( !( x -> r ) ) trans( x, x -> l );
        else
        {
            node *y = find_min( x -> r );
            del( x -> r, y -> key );
            x -> key = y -> key;
        }
    }

    x -> update();
    
    if ( x -> bf == 2 ) 
    {
        if ( x -> l -> bf >= 0 ) rrot( x );
        else if ( x -> l -> bf == -1 ) lrot( x -> l ), rrot( x );
    }

    else if ( x -> bf == -2 )
    {
        if ( x -> r -> bf <= 0 ) lrot( x );
        else if ( x -> r -> bf == 1 ) rrot( x -> r ), lrot( x );
    }
}

int order_of_key( node *x, int key )
{
    if ( x == NULL ) return 0;
    if ( x -> key <= key )
    {
        return 1 + ( x -> l ? x -> l -> sz : 0 ) + order_of_key( x -> r, key );
    }
    return order_of_key( x -> l, key );
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    root = NULL;
    int n, x;
    cin >> n;
    while ( n-- )
    {
        string s;
        cin >> s >> x;
        if ( s == "INS" ) insert( root, new node( x ) );
        else if ( s == "DEL" ) del( root, x );
        else if ( s == "ORD" ) cout << order_of_key( root, x ) << "\n";
    }
}
