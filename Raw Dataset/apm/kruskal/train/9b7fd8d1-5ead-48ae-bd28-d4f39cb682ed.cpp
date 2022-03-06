#include <bits/stdc++.h>




using namespace std;

ifstream fin("apm.in");

ofstream fout("apm.out");



int n, m, cost, p[400005];

vector<pair<int, int>> sol;



struct muchie {

    int a, b, d;

} v[400005];



bool cmp(muchie x, muchie y)

{

    return x.d < y.d;

}



int Find(int x)

{

    int r=x;

    while(r!=p[r])

        r=p[r];

    while(p[x]!=r)

    {

        int tmp=p[x];

        p[x]=r;

        x=tmp;

    }

    return r;

}



void Union(int x, int y)

{

    int rx=Find(x);

    int ry=Find(y);

    if(rx!=ry)

        p[rx]=ry;

}



int main()

{

    fin >> n >> m;

    for(int i=1; i<=m; i++)

        fin >> v[i].a >> v[i].b >> v[i].d;

    sort(v+1, v+m+1, cmp);

    for(int i=1; i<=n; i++)

        p[i]=i;

    for(int i=1; i<=m && sol.size()<(n-1); i++)

        if(Find(v[i].a)!=Find(v[i].b))

        {

            cost+=v[i].d;

            Union(v[i].a, v[i].b);

            sol.push_back({v[i].a, v[i].b});

        }

    fout << cost << "\n" << n-1 << "\n";

    for(int i=0; i<n-1; i++)

        fout << sol[i].first << " " << sol[i].second << "\n";

    return 0;

}
