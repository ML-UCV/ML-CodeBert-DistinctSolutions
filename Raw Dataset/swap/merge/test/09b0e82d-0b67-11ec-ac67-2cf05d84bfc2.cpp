#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>


const int DIM = 50100;

const int EXP = 26;

using namespace std;



int N, ok, Aux[DIM]; long long sol; char A[DIM], B[DIM];

vector <int> L[EXP]; int P[DIM], S1[EXP], S2[EXP], V[DIM];



void merge_sort( int left, int right ) {

    if( left == right ) return;



    int middle = left + ( right - left ) / 2;

    int index1, index2 = middle, pos = left;



    merge_sort( left, middle );

    merge_sort( middle + 1, right );



    for( index1 = left; index1 <= middle; index1 ++ ) {

        while( index2 < right && P[index1] > P[index2 + 1] )

            index2 ++;

        sol += index2 - middle;

    }



    index1 = left; index2 = middle + 1;

    while( index1 <= middle || index2 <= right ) {

        if( index1 > middle ) Aux[pos++] = P[index2++]; else

        if( index2 > right ) Aux[pos++] = P[index1++]; else

        if( P[index1] <= P[index2] )

            Aux[pos++] = P[index1++];

        else

            Aux[pos++] = P[index2++];

    }



    for( int i = left; i <= right; i ++ )

        P[i] = Aux[i];



    return;

}



int main () {



    freopen( "swap.in" , "r", stdin );

    freopen( "swap.out", "w", stdout );



    scanf( "%s %s", A + 1, B + 1 );

    N = strlen( A + 1 );



    for( int i = 1; i <= N; i ++ ) {

        S1[A[i] - 'a'] ++;

        S2[B[i] - 'a'] ++;

        V[i] = S1[A[i] - 'a'];

        L[B[i] - 'a'].push_back( i );

    }



    ok = 1;

    for( int i = 0; i < 26; i ++ )

        if( S1[i] != S2[i] ) ok = 0;



    if( ok == 0 )

        printf( "-1\n" );

    else {

        for( int i = 1; i <= N; i ++ )

            P[i] = L[A[i] - 'a'][V[i] - 1];



        merge_sort( 1, N );

        printf( "%lld\n", sol );

    }



    return 0;

}
