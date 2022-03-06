#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>






using namespace std;



ifstream fin("apm.in");

ofstream fout("apm.out");



struct muchii

{

    bool use;

    int a,b,cost;

} w[400001];



int v[400001];

int m,n;



bool compara(muchii vs, muchii vd)

{

    return vs.cost<vd.cost;

}



void make()

{

    for(int i=1; i<=n; i++)

        v[i]=i;

}



int rad(int x)

{

    int t,s = x;

    while(s != v[s])

        s=v[s];

    while(x!=s)

    {

        t=v[x];

        v[x]=s;

        x=t;

    }

    return s;

}



void add(int x,int y)

{

    x=rad(x);

    y=rad(y);

    v[x]=y;

}



void afis(int s, int i, int cnt)

{

    if(w[i].use == true )

    {

        s=s+w[i].cost;

        cnt++;

    }

    if(i==m)

    {

        fout<<s<<'\n';

        fout<<cnt<<'\n';

        if(w[i].use==true ) fout<<w[i].a<<' '<<w[i].b<<'\n';

    }

    else

    {

        afis(s,i+1,cnt);

        if(w[i].use==true ) fout<<w[i].a<<' '<<w[i].b<<'\n';

    }

}



void solve()

{

    for(int i=1; i<=m; i++)

    {

        if(rad(w[i].a)!=rad(w[i].b))

        {

            add(w[i].a,w[i].b);

        }

        else w[i].use=false;

    }



    afis(0,1,0);

}



void read()

{

    fin>>n>>m;

    make();

    for(int i=1; i<=m; i++)

    {

        fin>>w[i].a>>w[i].b>>w[i].cost;

        w[i].use=true;

    }

    sort(w+1,w+1+m, compara);



}



int main()

{

    read();

    solve();

    return 0;

}
