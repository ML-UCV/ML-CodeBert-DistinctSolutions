#include<stdio.h>
#include<stdlib.h>




int X[1000],Y[1000],Z[1000],V[101],A[101],n,m,k;



void read()

{

    int i;



    freopen("party.in","r",stdin);

    scanf("%d%d",&n,&m);

    for(i=0;i<m;++i)

        scanf("%d%d%d",X+i,Y+i,Z+i);

}



void solve()

{

    int i;



    srand(7);

    while(1)

    {

        for(i=0;i<m && V[X[i]]^((Z[i]&2)!=0)|V[Y[i]]^Z[i]&1;++i);

        if(i==m)

            break;

        if(rand()&1)

            V[X[i]]^=1;

        else

            V[Y[i]]^=1;

    }



    for(i=1;i<=n;++i)

        if(V[i])

            A[k++]=i;

}



void write()

{

    int i;



    freopen("party.out","w",stdout);

    printf("%d\n",k);

    for(i=0;i<k;++i)

        printf("%d\n",A[i]);

}



int main()

{

    read();

    solve();

    write();

    return 0;

}
