#include<fstream>
#include<algorithm>
using namespace std;

ifstream fin("schi.in");

ofstream fout("schi.out");

int sol[30001],aint[90000],v[30001];

int rez,poz,n;

void query(int nod, int st, int dr)

{

    if(st==dr)

    {

        rez=st;

        return ;

    }

    int mid=(st+dr)/2;

    if(poz<=aint[2*nod])

        query(2*nod,st,mid);

    else

    {

        poz-=aint[2*nod];

        query(2*nod+1,mid+1,dr);

    }

}

void update(int nod, int st, int dr)

{

    if(st==dr)

    {

        aint[nod]=0;

        return ;

    }

    int mid=(st+dr)/2;

    if(poz<=mid)

        update(2*nod,st,mid);

    else

        update(2*nod+1,mid+1,dr);

    aint[nod]=aint[2*nod]+aint[2*nod+1];

}

void build(int nod,int st, int dr)

{

    if(st==dr)

    {

        aint[nod]=1;

        return ;

    }

    int mid=(st+dr)/2;

    build(2*nod,st,mid);

    build(2*nod+1,mid+1,dr);

    aint[nod]=aint[2*nod]+aint[2*nod+1];

}

int main ()

{

 fin>>n;

 for(int i=1;i<=n;i++)

        fin>>v[i];

    build(1,1,n);

    for(int i=n;i>=1;i--)

    {

        poz=v[i];

        query(1,1,n);

        sol[rez]=i;

        poz=rez;

        update(1,1,n);

    }

    for(int i=1;i<=n;i++)

        fout<<sol[i]<<'\n';

 return 0;

}
