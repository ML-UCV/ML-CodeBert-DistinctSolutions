#include <bits/stdc++.h>
using namespace std;



ifstream fin("ctc.in");

ofstream fout("ctc.out");



vector < vector <int> > G, Gt;

vector <int> s, viz;

queue <int> C;

int nr;



void Dfs2(int x)

{

    viz[x] = nr;

    C.push(x);

    for(int i=0; i<Gt[x].size(); i++)

        if(viz[ Gt[x][i] ] == -1)

            Dfs2(Gt[x][i]);

}



void Dfs1(int x)

{

    viz[x] = -1;

    for(int i=0; i<G[x].size(); i++)

        if(viz[ G[x][i] ] == 0)

            Dfs1(G[x][i]);

    s.push_back(x);

}



int main()

{

    int n, m, x, y;

    fin>>n>>m;

    G.resize(n+1); Gt.resize(n+1); viz.resize(n+1);

    while(m)

    {

        fin>>x>>y;

        G[x].push_back(y);

        Gt[y].push_back(x);

        m--;

    }



    for(int i=1; i<=n; i++)

     if(viz[i] == 0)

      Dfs1(i);



    for(int i=s.size()-1; i>=0; i--)

     if(viz[s[i]] == -1)

        {

            nr++;

            Dfs2(s[i]);

        }

    fout<<nr<<"\n";

    int p=C.front();

    while(!C.empty())

    {

        if(viz[C.front()] != viz[p])

            fout<<"\n"<<C.front()<<" ";

        else

            fout<<C.front()<<" ";

        p=C.front();

        C.pop();

    }

    return 0;

}
