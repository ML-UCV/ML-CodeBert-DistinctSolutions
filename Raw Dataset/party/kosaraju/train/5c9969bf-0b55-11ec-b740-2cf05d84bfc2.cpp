#include <fstream>
#include <vector>
using namespace std;

fstream f1("party.in", ios::in);

fstream f2("party.out", ios::out);

int n, m, viz[205], l[205], nrl, sol[205], ctc[205], nrcomp, nrsol;

vector<int> v[205], vr[205], comp[205];

int neg(int nod)

{

    if(nod<=n) return n+nod;

    else return nod-n;

}

void mu(int x, int y)

{

    v[x].push_back(y);

    vr[y].push_back(x);

}

void citire()

{

    int i, x, y, cer;

    f1>>n>>m;

    for(i=1; i<=m; i++)

    {

        f1>>x>>y>>cer;

        switch(cer)

        {

            case 0: {mu(neg(x), y); mu(neg(y), x);break;}

            case 1: {mu(neg(x), neg(y)); mu(y, x);break;}

            case 2: {mu(neg(y), neg(x)); mu(x, y);break;}

            case 3: {mu(x, neg(y)); mu(y, neg(x));break;}

        }

    }

}

void dfs(int nod)

{

    viz[nod]=1;

    for(auto it=v[nod].begin(); it!=v[nod].end(); ++it)

        if(!viz[*it])

           dfs(*it);

   nrl++; l[nrl]=nod;

}

void dfs2(int nod)

{

    ctc[nod]=nrcomp;

    comp[nrcomp].push_back(nod);

    for(auto it=vr[nod].begin(); it!=vr[nod].end(); ++it)

        if(!ctc[*it])

           dfs2(*it);

}

void kos()

{

    for(int i=1; i<=2*n; i++)

        if(!viz[i])

          dfs(i);

    for(int i=nrl; i>=1; i--)

        if(!ctc[l[i]])

          {

             nrcomp++;

             dfs2(l[i]);

          }

}

void solutie()

{

    int i;

    for(i=1; i<=2*n; i++) sol[i]=-1;
    for(i=nrcomp; i>=1; i--)

        if(sol[comp[i][0]]==-1)

    {

        for(auto it=comp[i].begin(); it!=comp[i].end(); ++it)

        {

            sol[*it]=1;

            sol[neg(*it)]=0;

        }

    }

    for(i=1; i<=n; i++)

    {

        if(sol[i]==-1) sol[i]=1;

        nrsol+=sol[i];

    }

    f2<<nrsol<<"\n";

    for(i=1; i<=n; i++)

        if(sol[i]) f2<<i<<"\n";

}

int main()

{

    citire();

    kos();

    solutie();

    return 0;

}
