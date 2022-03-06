#include <stdio.h>


using namespace std;

FILE *f,*g;

int arbint[4*30001],N,P,v[30002],S[30002],Value,NOD;

void CreateFirstTree(int Nod,int Left,int Right)

{

    int Middle=(Right+Left)/2;

    if(Right==Left)

    {

        arbint[Nod]=1;return;

    }

    if(P<=Middle)CreateFirstTree(Nod*2,Left,Middle);

    else

        CreateFirstTree(Nod*2+1,Middle+1,Right);

    arbint[Nod]=arbint[2*Nod]+arbint[2*Nod+1];



}

int M;

void Read()

{

    int i;

    M=N;

    for(i=1;i<=N;i++)

        fscanf(f,"%d",&v[i]),P=i,CreateFirstTree(1,1,N);

}

void DeletePozX(int Nod,int Left,int Right,int PP)

{

    int Middle=(Left+Right)/2;

    if(Left==Right)

    {

        S[Left]=NOD;arbint[Nod]=0;

        return;

    }

    if(PP<=arbint[2*Nod])

        DeletePozX(2*Nod,Left,Middle,PP);

    else

        DeletePozX(2*Nod+1,Middle+1,Right,PP-arbint[2*Nod]);

    arbint[Nod]=arbint[2*Nod]+arbint[2*Nod+1];

}

void Displaying()

{

    int i=1;

    while(M)

    {

        fprintf(g,"%d\n",S[i]);M--;i++;

    }

}

int main()

{

    f=fopen("schi.in","r");g=fopen("schi.out","w");

    fscanf(f,"%d",&N);

    Read();

    while(N)

    {

        NOD=N;

        DeletePozX(1,1,M,v[N]);

        N--;

    }

    Displaying();

    fclose(f);fclose(g);

    return 0;

}
