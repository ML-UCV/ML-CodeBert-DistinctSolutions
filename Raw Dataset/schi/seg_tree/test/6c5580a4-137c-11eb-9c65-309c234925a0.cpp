#include <fstream>






using namespace std;



ifstream f ( "schi.in" );

ofstream g ( "schi.out" );



int ait[3 * 30001], sol[30001], v[30001];



void update ( int node, int st, int dr ){

    if ( st == dr ){

        ait[node] = 1;

        return;

    }

    int mid = ( st + dr ) >> 1;

    update ( 2 * node, st, mid );

    update ( 2 * node + 1, mid + 1, dr );

    ait[node] = ait[2 * node] + ait[ 2 * node + 1];

}



int quary ( int node, int st, int dr, int k ){

    ait[node]--;

    if ( st == dr )

        return st;

    int mid = ( st + dr ) >> 1;

    if ( ait[2 * node] < k ){

        k -= ait[2 * node];

        return quary ( 2 * node + 1, mid + 1, dr, k );

    }

    else

        return quary ( 2 * node, st, mid, k );

}



int main()

{ int n, i;

    f >> n;

    update ( 1, 1, n );

    for ( i = 1; i <= n; i++ )

        f >> v[i];

    for ( i = n; i >= 1; i-- ){

        int poz = quary ( 1, 1, n, v[i] );

        sol[poz] = i;

    }

    for ( i = 1; i <= n; i++ )

        g << sol[i] << '\n';

    return 0;

}
