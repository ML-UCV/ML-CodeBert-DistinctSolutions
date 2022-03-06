#include <fstream>
#include <algorithm>
using namespace std;

ifstream fin("inv.in");

ofstream fout("inv.out");

int t[100001],aint[300001];

int k,n,sol,a,b,poz,nr,MOD=9917;

struct norm

{

    int poz,val;

}v[100001];

int cmp(norm a, norm b)

{

    if(a.val==b.val)

        return a.poz<b.poz;

    return a.val<b.val;

}

void update(int nod,int st,int dr)

{

    if(st==dr)

    {

        aint[nod]++;

        if(aint[nod]==MOD)

            aint[nod]=0;

        return ;

    }

    int mid=(st+dr)/2;

    if(poz<=mid)

        update(2*nod,st,mid);

    else

        update(2*nod+1,mid+1,dr);

    aint[nod]=(aint[2*nod]+aint[2*nod+1])%MOD;

}

void query(int nod,int st,int dr)

{

    if(a<=st&&b>=dr)

    {

        nr+=aint[nod];

        if(nr==MOD)

            nr=0;

    }

    else

    {

        int mid=(st+dr)/2;

        if(a<=mid)

            query(2*nod,st,mid);

        if(b>mid)

            query(2*nod+1,mid+1,dr);

    }

}

int main()

{

    fin>>n;

    for(int i=1;i<=n;i++)

    {

        fin>>v[i].val;

        v[i].poz=i;

    }

    sort(v+1,v+n+1,cmp);

    for(int i=1;i<=n;i++)

    {

        if(v[i].val!=v[i-1].val)

            k++;

        t[v[i].poz]=k;

    }

    for(int i=1;i<=n;i++)

    {

        a=t[i]+1;b=k;nr=0;

        query(1,1,k);

        sol=(sol+nr)%MOD;

        poz=t[i];

        update(1,1,k);

    }

    fout<<sol;

    return 0;

}
