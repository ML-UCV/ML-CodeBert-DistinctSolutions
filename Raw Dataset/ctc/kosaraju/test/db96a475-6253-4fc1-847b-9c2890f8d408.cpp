#include    <bits/stdc++.h>
using namespace std;
int N,M;

vector<int>Graf1[100001],Graf2[100001];

stack <int> stiva;



short int vizitat[100001];



int Nrctc;

vector <int> Ctc[100001];

ifstream in("ctc.in");

ofstream out("ctc.out");

void citire()

{ in>>N>>M;

  for(int i=1;i<=M;i++)

  { int x,y;

    in>>x>>y;

    Graf1[x].push_back(y);

    Graf2[y].push_back(x);

  }

}

void dfs1(int k)

{ vizitat[k]=1;

  for(size_t i=0;i<Graf1[k].size();i++)

  { int Vecin=Graf1[k][i];

    if(!vizitat[Vecin])

        dfs1(Vecin);

  }

  stiva.push(k);

}

void dfs2(int k)

{ vizitat[k]=2;

  Ctc[Nrctc].push_back(k);

  for(int i=0;i<Graf2[k].size();i++)

  { int Vecin=Graf2[k][i];

     if(vizitat[Vecin]==1)

        dfs2(Vecin);

  }

}

void rezolvare()

{ for(int i=1;i<=N;i++)

     if(!vizitat[i])

        dfs1(i);

 while(!stiva.empty())

 { int nod=stiva.top();

     if(vizitat[nod]==1)

      {Nrctc++;

      dfs2(nod);

      }

     stiva.pop();

 }

}

void afisare()

{ out<<Nrctc<<'\n';

  for(int i=1;i<=Nrctc;i++)

    {for(int j=0;j<Ctc[i].size();j++)

        out<<Ctc[i][j]<<' ';

    out<<'\n';

    }

}

int main()

{ citire();

  rezolvare();

  afisare();

    return 0;

}
