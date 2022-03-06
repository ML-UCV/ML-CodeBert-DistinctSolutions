#include <stdio.h>
#include <deque>
#include <vector>
#include <cstring>
using namespace std;

FILE *f,*g;

vector <int> graph[100010],grapht[100010],ctc[100010];

deque <int> Q;

int N,M,been[100010],Nr;

void Read()

{

    int i,X,Y;

    fscanf(f,"%d %d",&N,&M);

    for(i=1;i<=M;++i)

    {

        fscanf(f,"%d %d",&X,&Y);

        graph[X].push_back(Y);

        grapht[Y].push_back(X);

    }

}

void DFS(int Node)

{

    int i,t=graph[Node].size();

    been[Node]=1;

    for(i=0;i<t;++i)

        if(!been[graph[Node][i]])DFS(graph[Node][i]);

    Q.push_back(Node);

}

void DFST(int Node)

{

    int i,t=grapht[Node].size();

    been[Node]=1;

    for(i=0;i<t;++i)

        if(!been[grapht[Node][i]])DFST(grapht[Node][i]);

    ctc[Nr].push_back(Node);

}

void Solve()

{

    int i,Node;

    for(i=1;i<=N;++i)

        if(!been[i])DFS(i);

    memset(been,0,sizeof(been));

    while(!Q.empty())

    {

        Node=Q.back();Q.pop_back();

        if(!been[Node])

        {

            ++Nr;

            DFST(Node);

        }

    }

}

void Displaying()

{

    int i,j;

    fprintf(g,"%d\n",Nr);

    for(i=1;i<=Nr;++i,fprintf(g,"\n"))

        for(j=0;j<ctc[i].size();++j)fprintf(g,"%d ",ctc[i][j]);

}

int main()

{

    f=fopen("ctc.in","r");g=fopen("ctc.out","w");

    Read();Solve();Displaying();

    fclose(f);fclose(g);

    return 0;

}
