#include <fstream>
#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std;





ifstream fin("ctc.in");

ofstream fout("ctc.out");

int n, m, ctc;

stack <int> s;

vector <int> v[100005], t[100005], af[100005];

bool viz[100005];



void read()

{

    fin>>n>>m;

    for(int i=1; i<=m; i++)

    {

    int x, y;

    fin>>x>>y;

    v[x].push_back(y);

    t[y].push_back(x);

    }

}



void dfs(int nod)

{

     cout<<nod<<'\n';

     viz[nod]=true;

     for(unsigned int i=0; i<v[nod].size(); i++)

     {

     int nnod=v[nod][i];

     if(!viz[nnod]) dfs(nnod);

     }

     s.push(nod);

}



void dfs2(int nod)

{

    viz[nod]=false;

    af[ctc].push_back(nod);

    for(unsigned int i=0; i<t[nod].size(); i++)

    {

    int nnod=t[nod][i];

    if(viz[nnod]) dfs2(nnod);

    }

}



int main()

{

    read();

    for(int i=1; i<=n; i++)

    {

    if(!viz[i]) dfs(i);

    }

    while(!s.empty())

    {

    int x=s.top();

    s.pop();

    if(viz[x]) {ctc++; dfs2(x);}

    }

    fout<<ctc<<'\n';

    for(int i=1; i<=ctc; i++){

    for(unsigned int j=0; j<af[i].size(); j++)

    fout<<af[i][j]<<" ";

    fout<<'\n';

    }

    return 0;

}
