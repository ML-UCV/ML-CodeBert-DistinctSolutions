#include<algorithm>
#include<vector>
#include<fstream>
#include<iostream>
#include<cstdio>
#include<iomanip>.
#include<cmath>
using namespace std;



ifstream in("cmap.in");

ofstream out("cmap.out");



class POINT

{

public :

    long long x,y;







    friend bool mycompx(POINT a,POINT b);

    friend bool mycompy(POINT a,POINT b);





    friend long long point_distance(POINT a, POINT b);



};



bool mycompy(POINT a,POINT b)

{

    return a.y < b.y;

}





bool mycompx(POINT a,POINT b)

{

    return a.x < b.x;

}



long long squared(long long x)

{

    return x*x;



}





POINT v_sortedx[100000 + 5];

POINT strip[100000 + 5];





int n;



void read_data()

{

    in >> n;



    for(int i = 1 ; i<=n ; ++i)

    {

        in>>v_sortedx[i].x;

        in>>v_sortedx[i].y;

    }



}



long long point_distance(POINT a, POINT b)

{

    long long lat_1 = b.x - a.x;

    long long lat_2 = b.y - a.y;



    return lat_1*lat_1 + lat_2*lat_2;

}
long long small_dist(int left,int right)

{



    int i,j;

    long long dist = 0xFFFFFFFFFFFFF;



    for(i = left ; i < right ; ++i)

        for( j = i+1 ; j <=right ; ++j)

        {

            long long temp = point_distance(v_sortedx[i],v_sortedx[j]);

            if( temp < dist)

                dist = temp;

        }



    return dist;

}





long long min_distance(int left,int right)

{

    if(right - left < 3)

    {

        return small_dist(left,right);

    }





    int m = (left + right ) / 2;



    long long d1 = min_distance(left,m);

    long long d2 = min_distance(m,right);



    long long d = d1 < d2 ? d1 : d2;



    int k = 0;



    for(int i = left ; i<=right ; ++i)

    {

        if(squared(v_sortedx[i].x - v_sortedx[m].x) < d)

            strip[++k] = v_sortedx[i];

    }



    sort(strip+1,strip+k+1,mycompy);



    int l;

    for(int i = 1 ; i<=k ; ++i)

    {

        l = 0;

        for(int j = i + 1; l<7 && j <=k ; ++j,++l)

        {

            long long dist = point_distance(strip[i],strip[j]);

            if(dist < d)

                d = dist;

        }

    }



    return d;

}
int main()

{

    read_data();





    sort(v_sortedx+1,v_sortedx+n+1,mycompx);



    long long d;



    d = min_distance(1,n);



    out<<fixed<<setprecision(6)<<sqrt(d);



    return 0;





}
