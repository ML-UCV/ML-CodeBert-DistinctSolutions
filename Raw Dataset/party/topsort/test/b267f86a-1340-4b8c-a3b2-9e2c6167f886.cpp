#include <cstdio>
#include <vector>
#include <algorithm>


using namespace std;



vector < vector < int > > lv,lv2;

vector <int> noduri,v,f,plus,minus;

int n,m,i,j,pas,ct=0;



int neg(int x)

{

    if (x<=n)

        return x+n;

    else

        return x-n;

}



void citire()

{

    int a,b,t;

    scanf("%d%d\n",&n,&m);

    lv.resize(2*n+1);

    for (i=0;i<m;i++)

    {

        scanf("%d %d %d\n",&a,&b,&t);

        if (t==0)

        {

            lv[neg(a)].push_back(b);

            lv[neg(b)].push_back(a);

        }

        else if (t==1)

        {

            lv[neg(a)].push_back(neg(b));

            lv[b].push_back(a);

        }

        else if (t==2)

        {

            lv[a].push_back(b);

            lv[neg(b)].push_back(neg(a));

        }

        else if (t==3)

        {

            lv[a].push_back(neg(b));

            lv[b].push_back(neg(a));

        }

    }

}



void sorttop(int nod)

{

    int i;

    v[nod]=1;

    for (i=0;i<lv[nod].size();i++)

        if (v[lv[nod][i]]==0)

            sorttop(lv[nod][i]);

    noduri.push_back(nod);

}



void dfs(int nod)

{

    int i;

    f[nod]=ct;

    for (i=0;i<lv2[nod].size();i++)

        if (f[lv2[nod][i]]==0)

            dfs(lv2[nod][i]);

}



int main()

{

    freopen("party.in","r",stdin);

    freopen("party.out","w",stdout);

    citire();

    v.resize(2*n+1);

    for (i=1;i<=2*n;i++)

        if (v[i]==0)

            sorttop(i);

    reverse(noduri.begin(), noduri.end());

    lv2.resize(2*n+1);

    for (i=1;i<=2*n;i++)

        for (j=0;j<lv[i].size();j++)

            lv2[lv[i][j]].push_back(i);

    f.resize(2*n+1);

    for (i=0;i<noduri.size();i++)

        if (f[noduri[i]]==0)

        {

            ct++;

            dfs(noduri[i]);

        }

    ct=0;

    for (i=1;i<=n;i++)

        if (f[i]>f[i+n])

            ct++;

    printf("%d\n",ct);

    for (i=1;i<=n;i++)

        if (f[i]>f[i+n])

            printf("%d\n",i);

    return 0;

}
