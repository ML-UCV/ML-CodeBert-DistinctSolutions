#include <bits/stdc++.h>
using namespace std;

ifstream in("apm.in");

ofstream out("apm.out");

int n,m,c,p[200001],v[200001];

struct muchie

{ int c,x,y;

};

bool operator <(muchie a,muchie b)

{ return a.c>b.c;

}

priority_queue <muchie> h;

vector < pair <int,int> > r;

int main()

{ in>>n>>m;

  for(int i=1;i<=m;i++)

  { muchie a;

    in>>a.x>>a.y>>a.c;

    h.push(a);

  }

  while(!h.empty())

  { muchie a=h.top();

    pair <int,int> x=make_pair(h.top().x,h.top().y);

    h.pop();

    while(p[a.x]!=0)

      a.x=p[a.x];

    while(p[a.y]!=0)

      a.y=p[a.y];

    if(a.x==a.y)

       continue;

    if(v[a.x]<v[a.y])

       swap(a.x,a.y);

    c+=a.c;

    v[a.x]+=v[a.y]+1;

    p[a.y]=a.x;

    r.push_back(x);

  }

  out<<c<<'\n'<<r.size()<<'\n';

  for(auto it: r)

    out<<it.first<<" "<<it.second<<'\n';

  in.close();

  out.close();

  return 0;

}
