#include<fstream>
#include<math.h>
#include<vector>
#include<queue>






using namespace std;

ifstream in("dmin.in");

ofstream out("dmin.out");



long long n,m,nrd[1505];

long double dm[1505];

bool t[1505];



struct muchie

{ int v;

 long long c;

};



vector<struct muchie>g[1505];

vector<struct muchie>::iterator it;

queue<int>q;



void bellman()

{ long long i,crt;

 for(i=1;i<=n;i++)

  dm[i]=1000000000;

 q.push(1);

 t[1]=1;

 dm[1]=0;

 nrd[1]=1;

 while(!q.empty() )

 { crt=q.front();

  q.pop();

  t[crt]=0;

  for(it=g[crt].begin();it < g[crt].end();it++)

  { if(dm[it->v] - (dm[crt] + log(it->c) ) > 1e-10 )

   { dm[it->v]=dm[crt] + log(it->c);

    nrd[it->v]=nrd[crt];

    if(nrd[it->v] > 104659)

     nrd[it->v]%=104659;

    if(!t[it->v])

    { q.push(it->v);

     t[it->v]=1;

    }

   }

   else if( (dm[crt] + log(it->c) - dm[it->v]) <= 1e-10)

   { nrd[it->v]+=nrd[crt];

    if(nrd[it->v] > 104659)

     nrd[it->v]%=104659;

   }

  }

 }

 for(i=2;i<=n;i++)

  out<<nrd[i]<<" ";

}

int main()

{ long long i,a,b,r;

 muchie w;

 in>>n>>m;

 for(i=1;i<=m;i++)

 { in>>a>>b>>r;

  w.c=r;

  w.v=b;

  g[a].push_back(w);

  w.v=a;

  g[b].push_back(w);

 }

 in.close();

 bellman();

 out.close();

 return 0;

}
