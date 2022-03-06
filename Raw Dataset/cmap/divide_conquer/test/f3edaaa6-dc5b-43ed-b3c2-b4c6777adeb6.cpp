#include <cstdio>
#include <cmath>


typedef double f64;



f64 INF=1e10;



struct Punct

{

    f64 x, y;



    Punct()

    {

        x=y=0;

    }

};



Punct v[100000], aux[100000];



f64 dist( Punct a, Punct b )

{

    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));

}



void interclasare( int st, int mid, int dr )

{

    int i=st, n=mid, j=mid, m=dr, k=0;



    while( i<n || j<m )

    {

        if( i<n && j<m && v[i].x<v[j].x )

        {

            aux[k]=v[i];

            i++;

        }

        else

            if( i<n && j<m )

            {

                aux[k]=v[j];

                j++;

            }

            else

                if( i<n )

                {

                    aux[k]=v[i];

                    i++;

                }

                else

                {

                    aux[k]=v[j];

                    j++;

                }



        k++;

    }



    for( i=st;i<dr;i++ )

        v[i]=aux[i-st];

}



f64 min( f64 a, f64 b )

{

    if( a>b )

        a=b;



    return a;

}



f64 cmap( int st, int dr )

{

    int med=(st+dr)/2, i, j;



    if( dr-st==1 )

        return INF;

    else

        if( dr-st==2 )

        {

            interclasare(st,st+1,dr);



            return dist(v[st],v[st+1]);

        }



    f64 d=min(cmap(st,med),cmap(med,dr));



    interclasare(st,med,dr);



    for( i=st;i<dr;i++ )

        for( j=i+1;j<i+6;j++ )

            d=min(d,dist(v[i],v[j]));



    return d;

}



int main()

{

    freopen( "cmap.in", "r", stdin );

    freopen( "cmap.out", "w", stdout );



    int n, i;



    scanf( "%d", &n );



    for( i=0;i<n;i++ )

        scanf( "%lf%lf", &v[i].x, &v[i].y );



    printf( "%f", cmap(0,n) );



    return 0;

}
