#include <bits/stdc++.h>


using namespace std;

ifstream f("stramosi.in");

ofstream g("stramosi.out");

int N,M,a,b,root,Cont[250006],maxim,cnt;

int P,Q,Deep[250006];

bool ok,viz[250006],viz2[250006];



vector < int > V[250006];

set < pair<int,int> > S[250006];

set < pair<int,int> > ::iterator it;



void DFS(int nod)

{

    viz[nod]=1;

    maxim++;

    Cont[nod]=maxim;

    for(unsigned int i=0;i<V[nod].size();i++)

    {

        int vecin=V[nod][i];

        if(!viz[vecin]) DFS(vecin);

    }

}



void BFS(int nod)

{

    queue < pair<int,int> > qu;

    viz2[nod]=1;

    qu.push({nod,1});

    S[1].insert({Cont[nod],nod});

    Deep[nod]=1;

    while(!qu.empty())

    {

        int vertex=qu.front().first;

        int niv=qu.front().second+1;

        viz2[vertex]=1;

        qu.pop();

        for(unsigned int i=0;i<V[vertex].size();i++)

        {

            int vecin=V[vertex][i];

            if(!viz2[vecin])

            {

                viz2[vecin]=1;

                Deep[vecin]=niv;

                S[niv].insert({Cont[vecin],vecin});

                qu.push({vecin,niv});

            }

        }

    }

}



int main()

{

    f>>N>>M;

    for(int i=1;i<=N;i++)

    {

        f>>a;

        V[a].push_back(i);

        if(!a) ok=1;

    }

    if(!ok) root=1;

    DFS(root);

    BFS(root);

    for(int i=1;i<=M;i++)

    {

        f>>Q>>P;

        if(Deep[Q]-P<=0) g<<0<<'\n';

        else

        {

            int level=Deep[Q]-P;

            int ID=Cont[Q];

            it=S[level].lower_bound({ID,level});

            it--;

            g<<(it->second)<<'\n';

        }

    }

    return 0;

}
