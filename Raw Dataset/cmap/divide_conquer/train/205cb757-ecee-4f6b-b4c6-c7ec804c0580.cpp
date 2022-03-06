#include <bits/stdc++.h>
using namespace std;

struct dd

{

    double x,y;

};

bool cmp(dd a,dd b)

{

    if(a.x==b.x)return a.y<b.y;

    return a.x<b.x;

}

bool cmp1(dd a,dd b)

{

    if(a.y==b.y)return a.x<b.x;

    return a.y<b.y;

}

double dist(dd a,dd b)

{

    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));

}

double min1(double a,double b)

{

    if(a-b<=-0.00001)return a;

    return b;

}

double bruteforce(dd P[],int n)

{

    double d1=dist(P[0],P[1]);

    for(int i=0;i<n-1;i++)

        for(int j=i+1;j<n;j++)

        d1=min1(d1,dist(P[i],P[j]));

        return d1;

}

double closeststripdist(dd str[],int n,double d)

{

    double min2=d;

    sort(str,str+n,cmp1);

    int i,j;

    for(i=0;i<n;i++)

        for(j=i+1;j<n&&str[j].y-str[i].y<=min2;j++)

        min2=min1(min2,dist(str[i],str[j]));

        return min2;

}

double closestdist(dd P[],int n)

{

    if(n<=3)

        return bruteforce(P,n);

    int mid=n/2;

    double dl=closestdist(P,mid);

    double dr=closestdist(P+mid,n-mid);

    dd str[n+5];

    double d=min1(dl,dr);

    int j=0,i;

    for(i=0;i<n;i++)

        if(fabs(P[i].x-P[mid].x)<=d)

        str[j]=P[i],j++;

    return min1(d,closeststripdist(str,j,d));

}

int main()

{

    freopen("cmap.in","r",stdin);

    freopen("cmap.out","w",stdout);

    int n,i;

    scanf("%d",&n);

    dd P[100005];

    for(i=0;i<n;i++)scanf("%lf%lf",&P[i].x,&P[i].y);

    sort(P,P+n,cmp);

    double x=closestdist(P,n);

    printf("%lf\n",x);

    return 0;

}
