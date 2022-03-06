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

} *X,*Y,*LY;



int n;



bool cmpX(punct a, punct b)

{

    return a.x < b.x;

}

bool cmpY(punct a, punct b)

{

    return a.y < b.y;

}



long long dist( punct a, punct b)

{

    long long X = 1LL * (a.x - b.x );

    long long Y = 1LL * ( a.y - b.y );

    return X*X + Y*Y ;

}



long long divide(int st,int dr,punct y[],int nr)

{

    if(dr-st == 1)

        return dist( X[st], X[dr] );

    if (dr-st == 2)

        return min(dist(X[st], X[st+1]),min(dist(X[st+1], X[dr]),dist(X[st], X[dr])));

    int mij=(st+dr)/2;

    int i,p=0,q=0;

    punct *SY = new punct[nr+1];

    punct *DY = new punct[nr+1];

    for( i = 0; i <= nr; i++)

        if( y[i].x < X[mij].x )

        {

            SY[p].x = y[i].x;

            SY[p].y = y[i].y;

            ++p;

        }

        else

        {

            DY[q].x = y[i].x;

            DY[q].y = y[i].y;

            ++q;

        }

    long long d1 = divide ( st, mij, SY, p-1 ) ;

    long long d2 = divide ( mij+1, dr,DY, q-1 ) ;

    long long d = min( d1, d2);

    long long d_sqrt = ceil(sqrt(d));

    int j,k=0;

    for( i = 0; i <= nr; i++)

        if( abs( y[i].x - X[mij].x ) <= d_sqrt )

        {

            LY[k].x = y[i].x;

            LY[k].y = y[i].y;

            k++;

        }

    for(i = 0; i < k ; i++)

        for(j = i + 1 ; j <= (i+7) && j < k; j++)

            d = min(d,dist(LY[i],LY[j]));



    delete [] SY;

    delete [] DY;

    return d;

}



int main()

{

    f >> n;

    X = new punct[n+1];

    Y = new punct[n+1];

    LY = new punct[n+1];

    for ( int i = 0; i < n ; i++)

    {

        f >> X[i].x >> X[i].y;

        Y[i].x = X[i].x;

        Y[i].y = X[i].y;

    }

    sort(X,X+n,cmpX);

    sort(Y,Y+n,cmpY);

    g << fixed << setprecision(6) << sqrt(divide(0,n-1,Y,n-1));

    delete [] X;

    delete [] Y;

    delete [] LY;

    f.close();

    g.close();

    return 0;

}
