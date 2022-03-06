#include <cstdio>
#include <algorithm>
#include <vector>
#include <climits>
#include <cmath>




FILE *f=fopen("cmap.in","r"), *g=fopen("cmap.out","w");



using namespace std;



struct Punct{ long long int x, y; } v[100005], w[100005], p[100005];

int N;



void Citire(){



    int i;



    fscanf(f,"%d\n",&N);

    for(i=1;i<=N;i++){

        fscanf(f,"%lld %lld\n",&v[i].x,&v[i].y);

    }



}



bool cmpx( Punct A, Punct B ){

    if( A.x < B.x || ( A.x == B.x && A.y < B.y ) )

        return 1;

    return 0;

}



long long int dist( Punct A, Punct B ){ return (B.x-A.x)*(B.x-A.x) + (B.y-A.y)*(B.y-A.y); }



void Interclasare( int k1, int mij, int k2 ){



    int i, j, k;



    i = k1;

    j = mij+1;

    for(k=k1;k<=k2;k++){

        if( j > k2 || ( i <= mij && v[i].y < v[j].y ) )

            w[k] = v[i++];

        else

            w[k] = v[j++];

    }

    for(k=k1;k<=k2;k++)

        v[k] = w[k];



}



long long int CB( int k1, int k2 ){



    int i, j, k, mij, indp;

    long long int dmin = LLONG_MAX;

    Punct dreaptaMIJ;



    if( k2-k1+1 <= 3 ){



        for(i=k1;i<k2;i++){

            for(j=i+1;j<=k2;j++){

                dmin = min( dmin, dist( v[i], v[j] ) );

            }

        }



        for(i=k1;i<k2;i++){

            for(j=i+1;j<=k2;j++){

                if( v[i].y > v[j].y || ( v[i].y == v[j].y && v[i].x > v[j].x ) )

                    swap( v[i], v[j] );

            }

        }



        return dmin;



    }



    mij = (k1+k2)/2;

    dreaptaMIJ = v[mij];



    dmin = min( CB(k1,mij), CB(mij+1,k2) );



    Interclasare(k1,mij,k2);



    indp = 0;

    for(k=k1;k<=k2;k++){

        if( (dreaptaMIJ.x-v[k].x)*(dreaptaMIJ.x-v[k].x) <= dmin ){

            p[++indp] = v[k];

        }

    }



    for(i=1;i<=indp;i++){

        for(j=i+1;j<=i+7&&j<=indp;j++){

            dmin = min( dmin, dist( p[i], p[j] ) );

        }

    }



    return dmin;



}



int main(){



    Citire();

    sort(v+1,v+N+1,cmpx);

    fprintf(g,"%.6lf\n", sqrt( CB(1,N)) );



return 0;

}
