# include <cstdio>
# include <cstring>






const char *FIN = "swap.in", *FOU = "swap.out" ;

const int MAX = 50005 ;



char sir[2][MAX];

int V[30][MAX], cnt[2][30], aux[30] ;

int A[MAX], B[MAX];

int sol ;



void solve ( int l, int r ) {

    int m = (l + r) >> 1 ;



    if (l == r) return ;



    solve ( l, m ) ;

    solve ( m + 1, r ) ;



    for ( int i = l, j = m + 1, k = l; i <= m || j <= r; )

        if ( j > r || ( i <= m && A[i] < A[j] ) ) {

            B[k++] = A[i++];

        } else {

            sol += ( m - i + 1 ), B[k++] = A[j++] ;

        }

    for ( int k = l; k <= r; ++k ) {

        A[k] = B[k] ;

    }

}



int main ( void ) {

    freopen ( FIN, "r", stdin ) ;



    fgets ( sir[0] + 1, MAX, stdin ) ;

    fgets ( sir[1] + 1, MAX, stdin ) ;



    int N = strlen ( sir[0] + 1 ) - 1 ;



    for ( int i = 1; i <= N; ++i ) {

        ++cnt[1][ ( sir[1][i] - 'a' ) ] ;

        V[ ( sir[1][i] - 'a' ) ][ aux[ ( sir[1][i] - 'a' ) ]++ ] = i ;

    }



    for ( int i = 1; i <= N; ++i ) {

        ++cnt[0][ ( sir[0][i] - 'a' ) ] ;



        if ( cnt[0][ ( sir[0][i] - 'a' ) ] > cnt[1][ ( sir[0][i] - 'a' ) ] ) {

            fprintf ( fopen ( FOU, "w" ), "-1\n" ) ;

            return 0 ;

        }



        A[i] = V[ ( sir[0][i] - 'a' ) ][ cnt[0][ ( sir[0][i] - 'a' ) ] - 1 ] ;

    }



    solve ( 1, N ) ;



    fprintf ( fopen ( FOU, "w" ), "%d", sol ) ;

}
