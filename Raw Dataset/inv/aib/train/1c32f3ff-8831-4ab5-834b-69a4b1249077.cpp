#include<fstream>
#include<algorithm>


using namespace std;

ifstream fin("inv.in");

ofstream fout("inv.out");

int vn[100001],aint[300001];

struct vec

{

    int nr, poz;

}v[100001];

bool cmp(vec x, vec y)

{

    if(x.nr==y.nr)

        return x.poz<y.poz;

    return x.nr<y.nr;

}

int n,poz,s,sol,k;

void normalizare()

{

    sort(v+1,v+n+1,cmp);

    for(int i=1;i<=n;i++)

        if(v[i].nr!=v[i-1].nr)

            vn[v[i].poz]=++k;

        else

            vn[v[i].poz]=k;

}

void query(int nod, int st, int dr, int x, int y )

{

    if(x<=st&&dr<=y)

    {

        s=(s+aint[nod])%9917;

        return ;

    }

    int mid=(st+dr)/2;

    if(x<=mid)

        query(2*nod,st,mid,x,y);

    if(y>mid)

        query(2*nod+1,mid+1,dr,x,y);

}

void update(int nod, int st, int dr)

{

    if(st==dr)

    {

        aint[nod]++;

        return ;

    }

    int mid=(st+dr)/2;

    if(poz<=mid)

        update(2*nod,st,mid);

    else

        update(2*nod+1,mid+1,dr);

    aint[nod]=(aint[2*nod]+aint[2*nod+1])%9917;

}

int main ()

{

 fin>>n;

 for(int i=1;i<=n;i++)

        fin>>v[i].nr,v[i].poz=i;

    normalizare();

    for(int i=1;i<=n;i++)

    {

        poz=vn[i];

        query(1,1,k,poz+1,k);

        update(1,1,k);

    }

    fout<<s;

 return 0;

}
