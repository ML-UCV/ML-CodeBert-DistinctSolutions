#include <bits/stdc++.h>


using namespace std;



ifstream f("ctc.in");

ofstream g("ctc.out");



vector<int> G[100010],GT[100010],comp[100010];

int n, m, nrcomp, nr, ord[100010];

bitset <100010> viz;



void DFS(int x){

    viz[x]=true;

    for(int i=0;i<G[x].size();++i)

        if(!viz[G[x][i]])

            DFS(G[x][i]);

    ord[++nr] = x;

}



void DFST(int x){

    comp[nrcomp].push_back(x);

    viz[x]=0;

    for(int i=0; i<GT[x].size();++i){

        if(viz[GT[x][i]])DFST(GT[x][i]);

    }

}



int main()

{



    f>>n>>m;

    for(int i=1,x,y;i<=m;++i){

        f>>x>>y;

        G[x].push_back(y);

        GT[y].push_back(x);

    }



    for(int i=1;i<=n;++i)

        if(!viz[i])DFS(i);



    for(int i=n;i>0;--i)

        if(viz[ord[i]]){

            nrcomp++;

            DFST(ord[i]);

        }



   g<<nrcomp<<"\n";

    for(int i=1;i<=nrcomp;++i){

        for(int j=0;j<comp[i].size();++j){

            g<<comp[i][j]<<" ";

        }

        g<<"\n";

    }



    return 0;

}
