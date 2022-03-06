#include <vector>
#include <fstream>


using namespace std;

ifstream fin ("ctc.in");

ofstream fout ("ctc.out");

vector<int> G[100002];

vector<int> GT[100002];

int n,nr,v[100002];

vector<int>tc[100002];

bool uz[100002];

void citire();

void postordine( int nod);

void dfs (int nod);

void afis();



int main()

{

    int i;

    citire();

    for(i=1;i<=n;i++)

        if(!uz[i])

            {

                uz[i]=1;

                postordine(i);

            }

    nr=0;

    for(i=n;i>0;i--)

        if(uz[v[i]])

        {

           nr++;

           dfs(v[i]);

        }

    afis();

    return 0;

}



void citire()

{

    int i,x,y,m;

    fin>>n>>m;

    for (i=1; i<=m;i++)

    {

        fin>>x>>y;

        G[x].push_back(y);

        GT[y].push_back(x);

    }

}



void postordine( int nod)

{

    for(int i=0;i<G[nod].size();i++)

        if(!uz[G[nod][i]])

        {

            uz[G[nod][i]]=1;

            postordine(G[nod][i]);

        }

    v[++nr]=nod;

}



void dfs (int nod)

{

    int i;

    uz[nod]=0;

    tc[nr].push_back(nod);

    for (i=0; i<GT[nod].size(); i++)

        if(uz[GT[nod][i]])

            dfs(GT[nod][i]);



}



void afis()

{

    int i,j;

    fout<<nr<<'\n';

    for(i=1;i<=nr;i++)

        {

            for(j=0;j<tc[i].size();j++)

                fout<<tc[i][j]<<" ";

            fout<<'\n';

        }



}
