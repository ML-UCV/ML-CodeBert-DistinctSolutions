#include <cstdio>
#include <vector>
#include <cmath>


using namespace std;



int a[100000001],b[100000001],c[100000001],d[100000001];



void intercl(int li,int lf)

{

    int m=(li+lf)/2,i,j,k;

    i=li;j=m+1;k=li;

    while(i<=m&&j<=lf)

        if(a[i]<a[j])

        {

            c[k]=a[i];

            d[k]=b[i];

            k++;

            i++;

        }

        else

        {

            c[k]=a[j];

            d[k]=b[j];

            k++;

            j++;

        }

    while(i<=m)

    {

        c[k]=a[i];

        d[k]=b[i];

        k++;

        i++;

    }

    while(j<=lf)

    {

        c[k]=a[j];

        d[k]=b[j];

        k++;

        j++;

    }

    for(i=li;i<=lf;i++)

    {

        a[i]=c[i];

        b[i]=d[i];

    }

}



void merge_sort(int li,int lf)

{

    if(li<lf)

    {

        int m=(li+lf)/2;

        merge_sort(li,m);

        merge_sort(m+1,lf);

        intercl(li,lf);

    }

}



double distanta(int x1,int y1,int x2,int y2)

{

    return sqrt((long long)(x1-x2)*(x1-x2)+(long long)(y1-y2)*(y1-y2));

}



double dist(int nr,int li,int lf)

{

    double aa,bb;

    double mn;

    if(nr==2)

        return distanta(c[li],d[li],c[lf],d[lf]);

    if(nr==3)

    {

        double segmin=distanta(c[li],d[li],c[li+1],d[li+1]);

        double l=distanta(c[li],d[li],c[lf],d[lf]);

        if(l<segmin) segmin=l;

        l=distanta(c[li+1],d[li+1],c[lf],d[lf]);

        if(l<segmin) segmin=l;

        return segmin;

    }

    aa=dist(nr/2,li,li+nr/2-1);

    bb=dist(nr/2+nr%2,li+nr/2,lf);

    if(aa<bb) mn=aa;

    else mn=bb;

    int i,j;

    double x=(c[li+nr/2-1]+c[li+nr/2])/2;

    double tz;

    for(i=li;i<=li+nr/2-1;i++)

    {

        if(x-c[i]<mn)

            for(j=li+nr/2;j<=lf;j++)

            {

                if(c[j]-x<mn)

                {

                    tz=distanta(c[i],d[i],c[j],d[j]);

                    if(tz<mn)

                        mn=tz;

                }

            }

    }

    return mn;

}



int main()

{

    FILE *f=fopen("cmap.in","r");

    FILE *g=fopen("cmap.out","w");

    int i,n;

    fscanf(f,"%d",&n);

    for(i=1;i<=n;i++)

        fscanf(f,"%d%d",&a[i],&b[i]);

    merge_sort(1,n);

    fprintf(g,"%.6f",dist(n,1,n));

    return 0;

}
