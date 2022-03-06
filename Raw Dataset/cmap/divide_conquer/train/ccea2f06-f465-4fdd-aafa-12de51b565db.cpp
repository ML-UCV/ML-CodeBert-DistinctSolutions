#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include<iomanip>
using namespace std;



ifstream be("cmap.in");

ofstream ki("cmap.out");



const long long inf=1e10;



struct point{

long long x,y;

};



bool xComp(const point& a, const point& b) {

    if(a.x==b.x) return a.y<b.y;

    else return a.x < b.x;

}



bool yComp(const point& a, const point& b) {

    if(a.y==b.y) return a.x< b.x;

    else return a.y < b.y;

}







long double distance(const point&a ,const point &b)

{



    long double d= sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));

    return d;

}





long double brute_force(vector<point>&p,int n)

{

    long double min1=inf;

    for(int i=0;i<n;i++)

        for(int j=i+1;j<n;j++){

            long double dist=distance(p[i],p[j]);

            min1=min(min1,dist);

        }

    return min1;

}



long double find_smallest_cmap(vector<point>&strip,int n,long double d)

{

    long double min=d;

    for(int i=0;i<n;i++)

        for(int j=i+1;j<n && (strip[j].y-strip[i].y)<min;j++)

            if(distance(strip[i],strip[j])<min)

                min=distance(strip[i],strip[j]);

    return min;

}







long double cmap(int n,vector<point>&px,vector<point>&py)

{

    if(n>3)

    {

        int m=n/2;

        point m_point=px[m];

        vector<point>pyl(m);

        vector<point>pyr(n-m);

        int l=0,r=0;

        vector<point>pxl(m);

        vector<point>pxr(n-m);

        for(int i=0;i<n;i++)

        {

            if(l<m && m_point.x>=px[i].x)

                pxl[l++]=px[i];

            else pxr[r++]=px[i];

        }

        long double minl,minr;

        minl=cmap(m,pxl,pyl);

        minr=cmap(n-m,pxr,pyr);

        long double d=min(minl,minr);

        vector<point>strip(n);

        int j=0;

        merge(pyl.begin(),pyl.end(),pyr.begin(),pyr.end(),py.begin(),yComp);

        for(int i=0;i<n;i++)

        {

            if(abs(py[i].x-m_point.x)<d){

                strip[j++]=py[i];}

        }

        return find_smallest_cmap(strip,j,d);

    }

    else

    {

       long double d = brute_force(px,n);

       py=px;

       sort(py.begin(),py.end(),yComp);

       return d;

    }

}



int main()

{

    int n;

    be>>n;

    vector<point> px(n);

    vector<point>py(n);

    for(int i=0;i<n;i++){

        long long x,y;

        be>>x>>y;

        px[i].x=x;

        px[i].y=y;



        py[i]=px[i];

    }

    sort(px.begin(),px.end(),xComp);



    ki<<fixed<<setprecision(6)<<cmap(n,px,py);



    return 0;

}
