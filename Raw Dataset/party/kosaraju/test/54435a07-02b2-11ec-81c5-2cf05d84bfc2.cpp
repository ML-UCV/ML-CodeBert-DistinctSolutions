#include <fstream>
#include <cstring>
#include <vector>
using namespace std;

ifstream cin("party.in");

ofstream cout("party.out");



vector <int> g[200010];

vector <int> gt[200010];

int st[200010],nr,sol[200010],tip ;

int idx[200010];

bool viz[200010];

int n,m,i,j,x,y,ok;



int negat(int x)

{

    if(x>n) return x-n;

    return x+n;



}

void muchie(int x, int y)

{

    g[x].push_back(y);

    gt[y].push_back(x);

}



void dfs(int nod)

{

    viz[nod]=1;



    for(int i=0; i<g[nod].size(); ++i)

    {

        if(!viz[g[nod][i]])

            dfs(g[nod][i]);



    }

    st[++nr] = nod;

}





void dfs2(int nod)

{

    if(ok==0) return;

    if(sol[nod] == 1)

    {

        ok=0;

        return;

    }



    sol[negat(nod)] = 1;



    viz[nod]=1;



    for(int i=0; i<gt[nod].size(); ++i)

        if(!viz[gt[nod][i]])

            dfs2(gt[nod][i]);



}



int main()

{

    cin>>n>>m;

    ok=1;

    for(i=1; i<=m; ++i)

    {

        cin>>x>>y>>tip;

        if(!tip) muchie(x+n,y),muchie(y+n,x);

        else if(tip==1) muchie(x+n,y+n),muchie(y,x);

        else if(tip==2) muchie(y+n,x+n),muchie(x,y);

        else muchie(x,y+n),muchie(y,x+n);

    }



    for(i=1; i<=2*n; ++i)

    {

        if(!viz[i])

            dfs(i);

    }



    memset(viz,0,sizeof(viz));

    for(i=nr; i>=1; --i)

    {

        if(!viz[st[i]] && !viz[negat(st[i])])

        {

            dfs2(st[i]);

        }

    }

    if(!ok)

    {

        cout<<-1;

        return 0;

    }



    nr=0;

    for(i=1; i<=n; ++i)

        if(sol[i]==1) nr++;



        cout<<nr<<"\n";



       for(i=1; i<=n; ++i)

        if(sol[i]==1)

            cout<<i<<"\n";

    return 0;

}
