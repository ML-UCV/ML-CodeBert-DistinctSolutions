#include<bits/stdc++.h>
using namespace std;

ifstream fin("cmap.in");

ofstream fout("cmap.out");



const int DIM = 1e5 + 5;



int N;

pair<int,int> arr[DIM], aux[DIM];



inline long long dist( pair<int,int> A, pair<int,int> B ){

    return 1LL * (A.first - B.first) * (A.first - B.first) +

           1LL * (A.second - B.second) * (A.second - B.second);

}



long long solve( int st, int dr ){

    if( dr - st == 1 ){

        long long ans = dist( arr[st], arr[dr] );

        if( arr[st].second > arr[dr].second )

            swap( arr[st], arr[dr] );

        return ans;

    }

    if( dr - st == 2 ){

        long long ans = dist( arr[st], arr[st + 1] );

        ans = min( ans, dist( arr[st], arr[dr] ) );

        ans = min( ans, dist( arr[st + 1], arr[dr] ) );

        if( arr[st].second > arr[st + 1].second )

            swap( arr[st], arr[st + 1] );

        if( arr[st].second > arr[dr].second )

            swap( arr[st], arr[dr] );

        if( arr[st + 1].second > arr[dr].second )

            swap( arr[st + 1], arr[dr] );

        return ans;

    }

    int mid = ( st + dr ) >> 1;

    long long ans = solve( st, mid );

    ans = min( ans, solve( mid + 1, dr ) );



    int p1 = st, p2 = mid + 1, k = st - 1;

    while( p1 <= mid && p2 <= dr ){

        if( arr[p1].second < arr[p2].second )

            aux[++k] = arr[p1++];

        else

            aux[++k] = arr[p2++];

    }

    while( p1 <= mid )

        aux[++k] = arr[p1++];

    while( p2 <= dr )

        aux[++k] = arr[p2++];

    for( int i = st; i <= dr; i++ )

        arr[i] = aux[i];



    k = 0;

    for( int i = st; i <= dr; i++ )

        if( (long long)( abs( (arr[mid].first - arr[i].first) ) ) <= ans )

            aux[++k] = arr[i];



    for( int i = 1; i <= k; i++ )

        for( int j = i + 1; j <= i + 7 && j <= k; j++ )

            ans = min( ans, dist( aux[i], aux[j] ) );



    return ans;

}





int main(){

    fin >> N;

    for( int i = 1; i <= N; i++ )

        fin >> arr[i].first >> arr[i].second;

    sort( arr + 1, arr + N + 1 );

    fout << setprecision(6) << fixed << sqrt( 1.0 * solve( 1, N ) ) << "\n";

    return 0;

}
