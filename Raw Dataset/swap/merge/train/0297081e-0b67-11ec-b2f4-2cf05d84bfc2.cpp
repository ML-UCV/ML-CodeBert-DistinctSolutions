#include<fstream>
#include<queue>
#include<cstring>
using namespace std;

ifstream fin("swap.in");

ofstream fout("swap.out");

int v[50005], n, sol;

char s[50005];

struct aint{

    int val;

    int lazy;

} A[200005];

queue<int> q[30];

void build( int nod, int st, int dr ){

    int Nst = (nod<<1);

    int Ndr = (nod<<1)|1;

    if( st > dr )

        return;

    if( st == dr ){

        A[nod].val = st;

        A[nod].lazy = 0;

    }else{

        int mid = ( st + dr ) >> 1;

        build( Nst, st, mid );

        build( Ndr, mid + 1, dr );

    }

}

void update( int nod, int st, int dr, int a, int b ){

    if( a > b )

        return;

    int Nst = (nod<<1);

    int Ndr = (nod<<1)|1;

    if( st > dr )

        return;

    if( a <= st && dr <= b ){

        A[nod].lazy++;

    }else{

        int mid = ( st + dr ) >> 1;

        if( a <= mid )

            update( Nst, st, mid, a, b );

        if( b > mid )

            update( Ndr, mid + 1, dr, a, b );

    }

}

int query( int nod, int st, int dr, int pos ){

    int Nst = (nod<<1);

    int Ndr = (nod<<1)|1;

    if( A[nod].lazy != 0 ){

        A[nod].val += A[nod].lazy;

        if( st != dr ){

            A[Nst].lazy += A[nod].lazy;

            A[Ndr].lazy += A[nod].lazy;

        }

        A[nod].lazy = 0;

    }

    if( st == dr ){

        return A[nod].val;

    }else{

        int mid = ( st + dr ) >> 1;

        if( pos <= mid )

            return query( Nst, st, mid, pos );

        else

            return query( Ndr, mid + 1, dr, pos );

    }

}

int main(){

    fin >> s;

    n = strlen( s );

    for( int i = 0; i < n; i++ ){

        q[ s[i] - 'a' ].push( i + 1 );

    }

    fin >> s;

    for( int i = 0; i < n; i++ ){

        if( q[ s[i] - 'a' ].empty() ){

            fout << "-1\n";

            return 0;

        }

        v[i + 1] = q[ s[i] - 'a' ].front();

        q[ s[i] - 'a' ].pop();

    }

    build( 1, 1, n );

    for( int i = 1; i <= n; i++ ){

        sol += query( 1, 1, n, v[i] ) - i;

        update( 1, 1, n, 1, v[i] - 1 );

    }

    fout << sol << "\n";

    return 0;

}
