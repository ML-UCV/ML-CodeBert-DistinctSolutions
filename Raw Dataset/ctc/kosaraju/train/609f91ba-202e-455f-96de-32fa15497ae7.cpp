#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int N, M, nrc;



vector<vector<int> > G, GT, CTC;

vector<bool> viz;

vector<int> Post;



ifstream f("ctc.in");

ofstream g("ctc.out");

void citire()

{

    int x, y;

    f >> N >> M;

    G = vector<vector<int> >(N + 1);

    GT = vector<vector<int> >(N + 1);

    CTC = vector<vector<int> >(N + 1);

    viz = vector<bool>(N + 1, 0);

    Post = vector<int>(N + 1);

    for(int i = 1; i <= M; i++)

    {

        f >> x >> y;

        G[x].push_back(y);

        GT[y].push_back(x);

    }

}

void afis()

{

    g << nrc << '\n';

    for(int i = 1; i <= nrc; ++i)

    {

        for(auto &x : CTC[i])

            g << x << ' ';

        g << '\n';

    }

}

void dfs(int vf)

{

    viz[vf] = 1;

    for(auto &x : G[vf])

        if(viz[x] == 0)

            dfs(x);

    Post.push_back(vf);

}



void dfsGT(int vf)

{

    viz[vf] = 0;

    CTC[nrc].push_back(vf);

    for(auto &x : GT[vf])

        if(viz[x] == 1)

            dfsGT(x);

}



void componente()

{

    for(int i = 1; i <= N; i++)

        if(viz[i] == 0)

            dfs(i);

    for(auto it = Post.rbegin(); it != Post.rend(); ++it)

        if(viz[*it] == 1)

        {

            nrc++;

            dfsGT(*it);

        }

}

int main()

{

    citire();

    componente();

    afis();

    return 0;

}
