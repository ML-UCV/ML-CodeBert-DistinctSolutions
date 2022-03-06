#include <fstream>
#include <vector>
#include <stack>


using namespace std;

ifstream f("ctc.in");

ofstream g("ctc.out");

int n,m,i,j,x,y,c;

int viz[100002];

vector < int > gf[100002],gft[100002];

vector < int > v[100002];

stack < int > q;

void dfs(int nod){

  viz[nod]=1;

  for(int i=0;i<gf[nod].size();i++){

    int x;

    x=gf[nod][i];

    if(viz[x]==0)

      dfs(x);

  }

  q.push(nod);

}

void dfst(int nod){

  viz[nod]=2;

  v[c].push_back(nod);

  for(int i=0;i<gft[nod].size();i++){

    int x;

    x=gft[nod][i];

    if(viz[x]==1)

      dfst(x);

  }

}

int main()

{

    f>>n>>m;

    for(i=1;i<=m;i++){

        f>>x>>y;

        gf[x].push_back(y);

        gft[y].push_back(x);

    }

    for(int i=1;i<=n;i++)

      if(viz[i]==0)

        dfs(i);

    while(!q.empty()){

        int x;

        x=q.top();

        if(viz[x]==1){

            c++;

            dfst(x);

        }

        q.pop();

    }

    g<<c<<'\n';

    for(i=1;i<=c;i++){

      for(j=0;j<v[i].size();j++)

        g<<v[i][j]<<' ';

      g<<'\n';

    }

    return 0;

}
