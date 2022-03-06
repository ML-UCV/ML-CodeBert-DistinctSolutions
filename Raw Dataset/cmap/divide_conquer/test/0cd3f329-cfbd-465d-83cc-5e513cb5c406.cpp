#include<iostream>
#include<fstream>
#include<cmath>
#include<algorithm>
#include<iomanip>


using namespace std;



ifstream f("cmap.in");

ofstream g("cmap.out");







struct punct

{

    int x, y;

}v[100010],w[100010];



int n;



bool cmpx (punct a, punct b)

{

    return a.x < b.x;

}



bool cmpy(punct a, punct b)

{

    return a.y < b.y;

}



long long dist ( punct a, punct b)

{

    long long difx = 1LL * (a.x - b.x );

    long long dify = 1LL * ( a.y - b.y );



    return difx * difx + dify * dify ;

}





long long divide ( int st, int dr)

{

    if( dr - st == 1)

        return dist( v[st], v[dr] );



    if ( dr-st == 2 )

        return min(dist(v[st], v[st+1]),min(dist(v[st+1], v[dr]),dist(v[st], v[dr])));



    int m=( st + dr ) / 2;

    long long S1 = divide ( st, m ) ;

    long long S2 = divide ( m+1, dr ) ;



    long long d = min( S1, S2);



    int i,j,k=0;



    long long delta = ceil(sqrt(d));



    for( i = st; i <= dr; i++)

    {

        if( abs( v[i].x - v[m].x ) <= delta )

        {

            w[k].x = v[i].x;

            w[k].y = v[i].y;

            k++;

        }

    }



    sort(w,w+k,cmpy);



    for(i = 0; i < k ; i++)

        for(j = i + 1 ; j <= (i+7) && j < k; j++)

        {

            d = min(d,dist(w[i],w[j]));

        }

    return d;

}



int main()

{

    int n;

    f >> n;



    for ( int i = 0; i < n ;i++)

        f >> v[i].x >> v[i].y;



    sort(v,v+n,cmpx);



    g << fixed << setprecision(6) << sqrt(divide(0,n-1));

    return 0;

}
