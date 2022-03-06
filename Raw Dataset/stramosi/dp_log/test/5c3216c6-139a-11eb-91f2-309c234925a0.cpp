#include <iostream>
#include<cstdio>


FILE * f=fopen("stramosi.in","r");

FILE * g=fopen("stramosi.out","w");



using namespace std;

int b[18][250001];



int main()

{

    int n,m,i,x,y,k=1;

    fscanf(f,"%d%d",&n,&m);

    for(i=1;i<=n;i++)

    {fscanf(f,"%d",&b[0][i]);



    }



int s=0,j;

do

{

    k=1<<s;



    s++;

}while(k<=n);



s=s-2;

for(i=1;i<=s;i++)

{

    for(j=1;j<=n;j++)

    {

        b[i][j]=b[i-1][b[i-1][j]];

    }

}

for(i=1;i<=m;i++)

    {

    s=0;

        fscanf(f,"%d%d",&x,&y);
        while(y>0)

        { s=0;

        k=1;

        while(k<=y)

        {

            s++;

            k=1<<s;



        }

        s--;

        k=k/2;



        x=b[s][x];

        y=y-k;





        }



   fprintf(g,"%d\n",x);



    }

    return 0;

}
