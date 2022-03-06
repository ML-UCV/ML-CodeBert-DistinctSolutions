#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;



int v[3][5010];

double C[5010];

int n,m;

struct s{

    double cost;

    int drum;

} a[1510];







void dijkstra()

{

    int i,t;

    for (i=1; i<=n; i++) a[i].cost=-1;

    a[1].cost=0; t=1;

    while (t)

    {

        t=0;

        for (i=1; i<=m*2; i++)

            if (a[v[1][i]].cost!=-1 && (a[v[2][i]].cost==-1 || a[v[2][i]].cost-a[v[1][i]].cost-C[i]>0.0000000001))

            {

                a[v[2][i]].cost=a[v[1][i]].cost+C[i];

                t=1;



            }

    }





    for (i=1; i<=n; i++) a[i].drum=0; a[1].drum=1;

    for (i=1; i<=m*2; i++)

        if ( abs(a[v[2][i]].cost-a[v[1][i]].cost-C[i])<=0.0000000001)

            {

                a[v[2][i]].drum=(a[v[2][i]].drum+a[v[1][i]].drum)%104659;

            }

}

void sw(int *a,int *b)

{

    int t=*a; *a=*b; *b=t;

}



void sw1(double *a,double *b)

{

    double t=*a; *a=*b; *b=t;

}



void qs(int left,int right)

{

    int i,j,p;

    i=left; j=right; p=v[1][(i+j)/2];

    while (i<j)

    {

        while (v[1][i]<p) i++;

        while (v[1][j]>p) j--;

        if (i<=j)

        {

            sw(&v[1][i],&v[1][j]);

            sw(&v[2][i],&v[2][j]);

            sw1(&C[i],&C[j]);

            i++;

            j--;

        }

    }

    if (i<right) qs(i,right);

    if (j>left) qs(left,j);

}



int main()

{

    int i,c;

    freopen("dmin.in","r",stdin);

    freopen("dmin.out","w",stdout);

    scanf("%i%i",&n,&m);

    for (i=1; i<=m*2; i++)

        if (i%2==1)

        {

            scanf("%i%i%i",&v[1][i],&v[2][i],&c);

            C[i]=log(c);



        }

        else{

            v[1][i]=v[2][i-1];

            v[2][i]=v[1][i-1];

            C[i]=C[i-1];

        }

    qs(1,m*2);





    dijkstra();

    for (i=2; i<=n; i++) printf("%i ",a[i].drum);

    return 0;

}
