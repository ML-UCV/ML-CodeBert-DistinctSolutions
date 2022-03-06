#include <bits/stdc++.h>
using namespace std;



ifstream f("apm.in");

ofstream g("apm.out");



struct muchie

{

    int x, y, w;

    inline bool operator<(muchie m)

    {return (w<m.w);}

};



vector<muchie> v;

vector<int> t, r;

int n, m;



void rd()

{

    f>>n>>m;

    v.resize(m);

    t.resize(n+1);

    for(int i=0; i<m; i++)

        f>>v[i].x>>v[i].y>>v[i].w;

    for(int i=1; i<=n; i++)

        t[i]=i;

}



int tata(int x)

{

    if(t[x]!=x)

        t[x]=tata(t[x]);

    return t[x];

}



inline void unite(int x, int y)

{

    t[tata(x)]=tata(y);

}



inline bool q(int x, int y)

{

    return (tata(x)==tata(y));

}



inline int Kruskal()

{

    int cost=0, i=0;

    sort(v.begin(), v.end());

    while(r.size()!=n-1)

    {

        while(q(v[i].x, v[i].y))

            i++;

        r.push_back(i);

        cost+=v[i].w;

        unite(v[i].x, v[i].y);

        i++;

    }

    return cost;

}



int main()

{

    rd();



    g<<Kruskal()<<'\n'<<n-1<<'\n';

    for(auto a:r)

        g<<v[a].x<<' '<<v[a].y<<'\n';



    f.close();

    g.close();

    return 0;

}
