#include <iostream>
#include <cstdio>
using namespace std;



int tab[25][250005],n,m,nod,stramos;



void gen()

{

    for(int i=1;i<=20;i++)

        for(int j=1;j<=n;j++)

            tab[i][j]=tab[i-1][tab[i-1][j]];

}



void caut(int nod_curent,int de_urcat)

{

    int i=0;

    for(i=0; (1<<i) <=de_urcat ;i++);

    --i;

    if(de_urcat==(1<<i))

     {

        printf("%d\n",tab[i][nod_curent]);

        return;

     }

    else

        caut(tab[i][nod_curent],de_urcat-(1<<i));

}



int main()

{

    freopen("stramosi.in","r", stdin);

    freopen("stramosi.out","w", stdout);

    scanf("%d %d",&n,&m);



    for(int i=1;i<=n;i++)

    {

        int tata;

        scanf("%d",&tata);



        tab[0][i]=tata;

    }

    gen();

    for(int i=1;i<=m;i++)

    {

        scanf("%d %d",&nod,&stramos);

        caut(nod,stramos);

    }

    return 0;

}
