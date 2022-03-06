#include <fstream>
#include <vector>






using namespace std;



bool existaSol;

int n, m;

bool sol[2*110];

bool viz[2*110];

vector <int> G[2*110], GT[2*110], ans;

int postordine[2*110], npostordine;



inline int neg(const int &x)

{

    if (x <= n)

        return x + n;

    return x - n;

}



void Read()

{

    ifstream f ("party.in");

    f>>n>>m;

    for (int i = 1; i<=m; ++i)

    {

        int x, y, cod;

        f>>x>>y>>cod;

        switch(cod)

        {

            case 0:



                break;

            case 1:



                y = neg(y);

                break;

            case 2:



                x = neg(x);

                break;

            case 3:



                x = neg(x);

                y = neg(y);

                break;

        }

        G[neg(x)].push_back(y);

        G[neg(y)].push_back(x);

        GT[y].push_back(neg(x));

        GT[x].push_back(neg(y));

    }

    f.close();

}



inline void DFS(const int node)

{

    viz[node] = true;

    for (vector <int>::iterator it = G[node].begin(); it!=G[node].end(); ++it)

        if (!viz[*it])

            DFS(*it);

    postordine[++npostordine] = node;

}



inline void DFST(const int node)

{

    if (sol[node])

    {

        existaSol = false;

        return ;

    }

    sol[neg(node)] = true;

    viz[node] = false;

    for (vector <int>::iterator it = GT[node].begin(); it!=GT[node].end(); ++it)

        if (viz[*it])

            DFST(*it);

}



void Solve()

{

    existaSol = true;

    int i, n2;

    n2 = n + n;

    for (i=1; i<=n2; ++i)

        if (!viz[i])

            DFS(i);

    for (i=n2; i; --i)

        if (viz[postordine[i]] && viz[postordine[neg(i)]])

            DFST(postordine[i]);

    for (i=1; i<=n; ++i)

        if (sol[i])

            ans.push_back(i);

}



void Write()

{

    ofstream g("party.out");

    g<<ans.size()<<"\n";

    for (vector <int>::iterator it = ans.begin(); it != ans.end(); ++it)

        g<<*it<<"\n";

    g.close();

}



int main()

{

    Read();

    Solve();

    Write();

    return 0;

}
