#include <bits/stdc++.h>


using namespace std;

int RMQ[250010][25];





int N,M;

ifstream f("stramosi.in");ofstream g("stramosi.out");

void Read()

{

    int i;

    f>>N>>M;

    for(i=1;i<=N;++i)f>>RMQ[i][0];

}

void BuildMatrix()

{

    int i,j,X;

    for(i=1;i<=N;++i)

        for(j=1;j<18;++j)

            RMQ[i][j]=RMQ[RMQ[i][j-1]][j-1];

}

int Search(int Node,int P)

{

    int i;

    for(i=0;(1<<i)<=P;++i)

    {

        if(P&(1<<i))

        {

            Node=RMQ[Node][i];

            if(!Node)return 0;

        }

    }

    return Node;

}

void SolveAndDisplaying()

{

    int X,Poz;

    while(M)

    {

        --M;

        f>>X>>Poz;

        g<<Search(X,Poz)<<"\n";

    }

}

int main()

{

    Read();BuildMatrix();SolveAndDisplaying();

    f.close();g.close();

    return 0;

}
