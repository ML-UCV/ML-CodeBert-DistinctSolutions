#include<iostream>
#include<fstream>
#include<cmath>
#include<algorithm>
#include<iomanip>




using namespace std;



ifstream f("cmap.in");

ofstream g("cmap.out");







struct point{

    int x, y;

}v[100100],w[100100];



int n;



bool cmp_x (point a, point b){

    return a.x < b.x;

}



bool cmp_y(point a, point b){

    return a.y < b.y;

}



long long dist ( point a, point b){

    long long difx = 1LL * (a.x - b.x );

    long long dify = 1LL * ( a.y - b.y );



    return difx * difx + dify * dify ;

}







long long divide ( int left, int right){

    if( right - left == 1){
        return dist( v[left], v[right] );

    }

    if ( right-left == 2 ){



        long long x,y,z;

        x=dist(v[left], v[left+1]);

        y=dist(v[left+1], v[right]);

        z=dist(v[left], v[right]);

        if((x<=y)&&(x<=z)){
            return x;

        }

        if((y<=x)&&(y<=z)){
            return y;

        }

         if((z<=x)&&(z<=y)){
            return z;

        }

    }



    int m=( left + right ) / 2;

    long long d1 = divide ( left, m ) ;

    long long d2 = divide ( m+1, right ) ;

    long long d = min( d1, d2);

    int i,j,k=0;

    long long delta = ceil(sqrt(d));

    for( i = left; i <= right; i++){

        if( abs( v[i].x - v[m].x ) <= delta ){

            w[k].x = v[i].x;

            w[k].y = v[i].y;

            k++;

        }

    }



    sort(w,w+k,cmp_y);



    for(i = 0;i < k ; i++)

        for(j = i + 1 ; j <= (i+7) && j < k; j++){

            if(dist(w[i],w[j])<d){
                d=dist(w[i],w[j]);

            }



        }

    return d;

}



int main(){

    int n;

    f>>n;

    for (int i =0;i<n;i++)

        f>>v[i].x>>v[i].y;

    sort(v,v+n,cmp_x);

    g<<fixed<<setprecision(6)<<sqrt(divide(0,n-1));

    f.close();

    g.close();





    return 0;

}
