#include <fstream>
#include <stack>
#include <vector>


using namespace std;



ifstream F("party.in");

ofstream G("party.out");



int n, m, A, B, x, y, k, K, sol[ 1005 ], w[ 205 ], z, p, q, r, s;

stack<int> st;

bool v[505];

vector< int > a[ 205 ];

vector< int > rev[ 205 ];



int Id( int x )

{

    if( x <= n ) x +=n;

    else x -= n;

    return x;

}



void dfs1( int nod )

{

    v[ nod ] = 1;

    vector< int > :: iterator it;

    for( it = a[ nod ].begin(); it != a[ nod ].end(); ++it )

        if( !v[ *it ] ) dfs1( *it );

    st.push( nod );

}



void dfs2( int nod )

{

    v[ nod ] = 0;

    w[ Id( nod ) ] = 1;

    vector< int > :: iterator it;

    for( it = rev[ nod ].begin(); it != rev[ nod ].end(); ++it )

        if( v[ *it ] ) dfs2( *it );

}



int main()

{

    F >> n >> m;

    for( int i = 1; i <= m; ++ i )

    {

        F >> A >> B >> z;

        if( !z )

        {

            x = A; y = B;

        }

        else if( z == 1 )

        {

            x = A; y = Id( B );

        }

        else if( z == 2 )

        {

            x = B; y = Id( A );

        }

        else

        {

            x = Id( A ); y = Id( B );

        }

        p = Id( x ); q = x;

        r = Id( y ); s = y;

        a[ p ].push_back( s );

        a[ r ].push_back( q );

        rev[ s ].push_back( p );

        rev[ q ].push_back( r );

    }

    for( int i = 1; i <= 2 * n; ++ i )

        if( !v[ i ] ) dfs1( i );

    while( !st.empty() )

    {

        x = st.top();

        if( v[ x ] && v[ Id( x ) ] )

            dfs2( x );

        st.pop();

    }

    for( int i = 1; i <= n; ++ i )

        if( w[ i ] )

            sol[ ++ K ] = i;

    G << K << '\n';

    for( int i = 1; i <= K; ++ i ) G << sol[ i ] << '\n';

    return 0;

}
