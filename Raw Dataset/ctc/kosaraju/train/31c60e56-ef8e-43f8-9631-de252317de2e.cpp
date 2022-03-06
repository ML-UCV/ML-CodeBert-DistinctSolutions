#include <fstream>
#include <vector>


using namespace std;

ifstream fi("ctc.in");

ofstream fo("ctc.out");

const int nmax=1e5;

int n, m, nr, cnt;

int viz[nmax+5], post[nmax+5];

vector <int> sol[nmax+5], G[nmax+5], GT[nmax+5];



void dfsPost(int nod)

{

    viz[nod]=1;

    for(auto vec:GT[nod])

        if(!viz[vec])

            dfsPost(vec);

    post[++nr]=nod;

}



void dfs(int nod)

{

    viz[nod]=0;

    sol[cnt].push_back(nod);

    for(auto vec:G[nod])

        if(viz[vec])

            dfs(vec);

}



int main()

{

    fi>>n>>m;

    for(int i=1; i<=m; i++)

    {

        int x, y;

        fi>>x>>y;

        G[x].push_back(y);

        GT[y].push_back(x);

    }

    for(int i=1; i<=n; i++)

        if(!viz[i])

            dfsPost(i);



    for(int i=n; i>=1; i--)

        if(viz[post[i]])

        {

            cnt++;

            dfs(post[i]);

        }



    fo<<cnt<<"\n";

    for(int i=1; i<=cnt; i++)

    {

        for(auto j:sol[i])

            fo<<j<<" ";

        fo<<"\n";

    }

    fi.close();

    fo.close();

    return 0;

}
