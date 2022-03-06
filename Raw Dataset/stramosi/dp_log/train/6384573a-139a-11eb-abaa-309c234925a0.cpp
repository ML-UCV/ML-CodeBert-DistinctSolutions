#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

FILE *f,*g;

int rmq[25][250002];

int log2[250002];

int n,m;

void read()

{

    fscanf(f,"%d %d",&n,&m);

    for(int i=1; i<=n; i++)

        fscanf(f,"%d",&rmq[0][i]);

}

void logarithm()

{

    for(int i=2;i<=n;i++)

        log2[i]=log2[i/2]+1;

}

void build()

{

    for(int i=1;i<=log2[n];i++)

        for(int j=1; j<=n; j++)

            rmq[i][j]=rmq[i-1][rmq[i-1][j]];

}

int querry(int nod, int lev)

{

    for(int i=0; (1<<i)<=lev; i++)

    {

        if((1<<i) & lev)

        {

            nod=rmq[i][nod];

            if(!nod)

                return 0;

        }

    }

    return nod;

}

int main()

{ int nod,lev;

    f=fopen("stramosi.in", "r");

    g=fopen("stramosi.out", "w");

    read();

    logarithm();

    build();

    for(int i=1;i<=m;i++)

    {

        fscanf(f,"%d %d",&nod,&lev);

        fprintf(g,"%d\n",querry(nod,lev));

    }



    fclose(f);

    fclose(g);

    return 0;

}
