#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

int n;



struct pct

{

    int x,y;

} a[100001],b[100001],c[100001];





int f1(pct x,pct y)

{

    return (x.x<y.x);

}



double dist(pct x,pct y)

{

    double d=sqrt((double)(x.x-y.x)*(double)(x.x-y.x)+

                  (double)(x.y-y.y)*(double)(x.y-y.y));

    return d;

}



void intercl(int li,int lf)

{

    int m=(li+lf)/2,i=li,j=m+1,k=li;

    while(i<=m&&j<=lf)

        if(b[i].y<b[j].y)c[k++]=b[i++];

        else c[k++]=b[j++];

    while(i<=m)c[k++]=b[i++];

    while(j<=lf)c[k++]=b[j++];

    for(i=li; i<=lf; i++)b[i]=c[i];

}



double dmin(int li,int lf)

{

    if(lf-li==1)

    {

        if(b[li].y>b[lf].y)swap(b[li],b[lf]);

        return dist(a[li],a[lf]);

    }

    if(lf-li==2)

    {

        double q=dist(a[li],a[li+1]);

        double w=dist(a[li+1],a[li+2]);

        double r=dist(a[li],a[li+2]);

        if(w<q)q=w;

        if(r<q)q=r;

        if(b[li].y>b[li+1].y)swap(b[li],b[li+1]);

        if(b[li].y>b[li+2].y)swap(b[li],b[li+2]);

        if(b[li+1].y>b[li+2].y)swap(b[li+1],b[li+2]);

        return r;

    }

    double d,d1;

    int m,i,np=0,xd;

    m=(li+lf)/2;

    d=dmin(li,m);

    d1=dmin(m+1,lf);

    if(d1<d)d=d1;

    xd=(a[m].x+a[m+1].x)/2;

    intercl(li,lf);

    for(i=li; i<=lf; i++)

        if(abs(b[i].x-xd)<d)c[++np]=b[i];

    int npr,j;

    for(i=1; i<np; i++)

    {

        npr=min(i+6,np);

        for(j=i+1; j<=npr; j++)

        {

            d1=dist(c[i],c[j]);

            if(d1<d)d=d1;

        }

    }

    return d;

}



int main()

{

    FILE *f=fopen("cmap.in","r");

    fscanf(f,"%d",&n);

    int i;

    for(i=1; i<=n; i++)

        fscanf(f,"%d%d",&a[i].x,&a[i].y);

    fclose(f);

    sort(a+1,a+n+1,f1);

    for(i=1; i<=n; i++)b[i]=a[i];

    f=fopen("cmap.out","w");

    fprintf(f,"%6.6f",dmin(1,n));

    fclose(f);

    return 0;

}
