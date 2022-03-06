#include <fstream>
#include <vector>
#include <cstring>
using namespace std;

const int N=100001;



ifstream fin("ctc.in");

ofstream fout("ctc.out");



vector<int>dus[N];

vector<int>intors[N];

vector<vector<int>>comp;

vector<int>stiva;

int n,m,x,y;

int viz[N];



void dfs(int nod)

{

    viz[nod]=1;

    for(auto it: dus[nod])

    {

        if(viz[it])continue;

        dfs(it);

    }

    stiva.push_back(nod);

}



void dfsIntors(int nod)

{

    viz[nod]=1;

    for(auto it:intors[nod])

    {

        if(viz[it])continue;

        dfsIntors(it);

    }

    comp.back().push_back(nod);

}



int main()

{

    fin>>n>>m;

    for(int i=1;i<=m;i++)

    {

        fin>>x>>y;

        dus[x].push_back(y);

        intors[y].push_back(x);

    }

    for(int i=1;i<=n;i++)

    {

        if(!viz[i])dfs(i);

    }

    memset(viz,0,sizeof(viz));

    for(int i=stiva.size()-1;i>=0;i--)

    {

        if(!viz[stiva[i]]){

            comp.push_back(vector<int>());

            dfsIntors(stiva[i]);

        }

    }

    fout<<comp.size()<<'\n';

    for(auto vec:comp){

        for(auto el:vec)fout<<el<<' ';

        fout<<'\n';

    }

    return 0;

}
