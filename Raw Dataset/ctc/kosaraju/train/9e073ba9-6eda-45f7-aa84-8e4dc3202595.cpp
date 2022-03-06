#include <fstream>
#include <vector>
#include <stack>




using namespace std;



ifstream fin("ctc.in");

ofstream fout("ctc.out");



vector <int> G[100005];

vector <int> GT[100005];

stack <int> postordine;

vector <int> Ctc[100005];

int viz[100005];

int n,m,X,NrCtc;



void citire()

{

    fin>>n>>m;

    for(int i=0,x,y; i<m; i++)

    {

        fin>>x>>y;

        G[x].push_back(y);

        GT[y].push_back(x);

    }

}



void DFS(int X)

{

    viz[X]=1;

    int N=G[X].size();

    for(int i=0; i<N; i++)

    {

        int vecin=G[X][i];

        if(!viz[vecin])

            DFS(vecin);

    }

    postordine.push(X);

}



void DFST(int X)

{

    viz[X]=2;

    Ctc[NrCtc].push_back(X);

    int N=GT[X].size();

    for(int i=0; i<N; i++)

    {

        int vecin=GT[X][i];

        if(viz[vecin]==1)

            DFST(vecin);

    }

}



void afisare()

{

    fout<<NrCtc<<'\n';;

    for(int i=1; i<=NrCtc; i++)

    {

        int N=Ctc[i].size();

        for(int j=0; j<N; j++)

        {

            fout<<Ctc[i][j]<<" ";

        }

        fout<<'\n';

    }

}



int main()

{

    citire();

    for(int i=1; i<=n; i++)

        if(!viz[i])

            DFS(i);

    while(!postordine.empty())

    {

        int X=postordine.top();

        if(viz[X]==1)

        {

            NrCtc++;

            DFST(X);

        }

        postordine.pop();

    }

    afisare();

    return 0;

}
