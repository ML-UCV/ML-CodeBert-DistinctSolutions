#include <bits/stdc++.h>


using namespace std;



ifstream fin("cmap.in");

ofstream fout("cmap.out");



struct coord

{

    long long x,y;

};



coord t[100001],v[100001];

int i,j,m,n,x,y;



bool funct(coord a, coord b)

{

    if (a.x>b.x) return 0;

    if (b.x>a.x) return 1;

    if (a.y>b.y) return 0;

    return 1;

}



bool compy(coord a,coord b)

{

    if (a.y>b.y) return 0;

    return 1;

}



double dist(coord a, coord b)

{

    double x=(a.x-b.x)*(a.x-b.x),y=(a.y-b.y)*(a.y-b.y);

    return sqrt(x+y);

}



double ds(int a,int b)

{

    double s,x,y,z;

    if (b-a<3)

    {

        if (b-a==1) return dist(t[a],t[b]);



        x=sqrt(1LL*(t[a].x-t[b].x)*(t[a].x-t[b].x)+(t[a].y-t[b].y)*(t[a].y-t[b].y));

        y=dist(t[a],t[a+1]);

        z=dist(t[a+1],t[b]);

        return min(x,min(y,z));

    }

    int mid=(a+b)/2,poz=0;

    x=ds(a,mid);

    y=ds(mid,b);

    s=min(x,y);

    for (i=a;i<=b;i++)

      if (abs(t[i].x-t[mid].x)<s) v[++poz]=t[i];



    sort(v+1,v+poz+1,compy);

    for (int i=1;i<poz;i++)

          for (j=i+1;j<=poz && j-i<8;j++)

          if (dist(v[i],v[j])<s) s=dist(v[i],v[j]);

    return s;





}



int main()

{

    fin>>n;

    for (i=1;i<=n;i++)

        fin>>t[i].x>>t[i].y;

    sort(t+1,t+n+1,funct);





    fout<<fixed<<setprecision(6)<<ds(1,n);

    return 0;

}
