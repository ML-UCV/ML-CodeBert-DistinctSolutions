#include <iostream>
#include <fstream>
#include <vector>


using namespace std;



ifstream f("ctc.in");

ofstream g("ctc.out");



vector<vector<int> > w, w2, ctc;

bool viz[100002];

int ap[100002];

int N, M, k, nrctc;



void dfs1(int x)

{

    viz[x] = 1;



    for(int i = 0; i < w[x].size(); i++)

    {

        if(!viz[w[x][i]])

            dfs1(w[x][i]);

    }

    k++;

    ap[k] = x;

}



void dfs2(int x)

{

    viz[x] = 0;

    ctc[nrctc].push_back(x);



    for(int i = 0; i < w2[x].size(); i++)

    {

        if(viz[w2[x][i]])

            dfs2(w2[x][i]);

    }

}



int main()

{

    f>> N >> M;



    w.resize(N + 2);

    w2.resize(N + 2);

    ctc.push_back({});



    int x, y;



    for(int i = 1; i <= M; i++)

    {

        f >> x >> y;

        w[x].push_back(y);

        w2[y].push_back(x);

    }



    for(int i = 1; i <= N; i++)

        if(!viz[i])

            dfs1(i);



    for(int i = N; i >= 1; i--)

    {

        if(viz[ap[i]] == 1)

        {

            nrctc++;

            ctc.push_back({});

            dfs2(ap[i]);

        }

    }



    g << nrctc << '\n';



    for(int i = 1; i <= nrctc; i++)

    {

        for(int j = 0; j < ctc[i].size(); j++)

            g << ctc[i][j] << ' ';

        g << '\n';

    }



}
