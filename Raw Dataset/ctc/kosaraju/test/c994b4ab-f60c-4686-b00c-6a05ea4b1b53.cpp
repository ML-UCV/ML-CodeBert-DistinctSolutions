#include <bits/stdc++.h>


using namespace std;



ifstream fin("ctc.in");

ofstream fout("ctc.out");



int N, M, nR;

bool Viz[100005],VizT[100005];

vector<int>Ad[100005],AdT[100005],Ord,TareCon[100005];



void citire()

{

    int x,y;

    fin>>N>>M;

    for(int i=1;i<=M;i++)

    {

        fin>>x>>y;

        Ad[x].push_back(y);

        AdT[y].push_back(x);

    }

}



void sortareTopologica(int x)

{

    Viz[x]=1;

    for(unsigned i=0;i<Ad[x].size();i++)

        if(!Viz[Ad[x][i]])

            sortareTopologica(Ad[x][i]);

    Ord.push_back(x);

}



void DFS(int x)

{

    VizT[x]=1;

    TareCon[nR].push_back(x);

    for(unsigned i=0;i<AdT[x].size();i++)

        if(!VizT[AdT[x][i]])

            DFS(AdT[x][i]);

}



int main()

{

    citire();

    for(int i=1;i<=N;i++)

        if(!Viz[i])

            sortareTopologica(i);

    for(int x=(int)Ord.size()-1;x>=0;x--)

        if(!VizT[Ord[x]])

        {

            nR++;

            DFS(Ord[x]);

        }

    fout<<nR<<'\n';

    for(int i=1;i<=nR;i++)

    {

        for(unsigned j=0;j<TareCon[i].size();j++)

            fout<<TareCon[i][j]<<" ";

        fout<<'\n';

    }

    return 0;

}
