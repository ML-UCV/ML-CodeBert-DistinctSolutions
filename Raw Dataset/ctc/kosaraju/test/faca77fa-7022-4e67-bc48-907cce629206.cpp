#include <fstream>
#include <vector>


using namespace std;



ifstream f("ctc.in");

ofstream g("ctc.out");



int n,m,nrc;



vector<vector<int> > G,GT,CTC;

vector<bool> viz;

vector<int> Post;



void citire()

{

    int x,y;

    f>>n>>m;



    G = vector<vector<int> >(n+1);

    GT = vector<vector<int> >(n+1);

    CTC = vector<vector<int> >(n+1);

    viz = vector<bool>(n+1,0);

    Post = vector<int>(n+1);



    for(int i=1;i<=m;i++)

    {

        f>>x>>y;

        G[x].push_back(y);

        GT[y].push_back(x);

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

    for(int i=1;i<=n;i++)

        if(viz[i] == 0)

            dfs(i);



    for(auto it = Post.rbegin(); it != Post.rend(); ++it)

        if(viz[*it] == 1)

        { nrc++;

            dfsGT(*it);

        }

}



void afis()

{

    g<<nrc<<'\n';

    for(int i=1;i<=nrc;++i)

    {

        for(auto x:CTC[i])

            g<<x<<' ';

        g<<'\n';

    }

}



int main()

{

    citire();

    componente();

    afis();

    return 0;

}
