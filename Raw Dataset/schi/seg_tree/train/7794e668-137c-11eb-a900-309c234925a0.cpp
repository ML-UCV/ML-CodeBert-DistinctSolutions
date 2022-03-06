#include <cstdio>


using namespace std;



const int NMAX = 30005;

int aint[NMAX*4];

int v[NMAX];

int sol[NMAX];

int n;



void build(int nod,int st,int dr)

{

    if(st == dr)

    {

        aint[nod] = 1;

        return;

    }

    int mij = (st+dr)/2;

    build(2*nod,st,mij);

    build(2*nod+1,mij+1,dr);

    aint[nod] = aint[2*nod]+aint[2*nod+1];

}



void update(int nod,int st,int dr,int pos,int val)

{

    if(st == dr)

    {

        aint[nod] = val;

        return;

    }

    int mij = (st+dr)/2;

    if(pos <= mij)

        update(2*nod,st,mij,pos,val);

    else

        update(2*nod+1,mij+1,dr,pos,val);

    aint[nod] = aint[2*nod] + aint[2*nod+1];

}



int query(int nod,int st,int dr,int val)

{

    if(st == dr)

        return st;

    int mij = (st+dr)/2;

    if(val <= aint[2*nod])

        return query(2*nod,st,mij,val);

    else

        return query(2*nod+1,mij+1,dr,val-aint[2*nod]);

}



int main()

{

    freopen("schi.in","r",stdin);

    freopen("schi.out","w",stdout);

    scanf("%d",&n);

    for(int i = 1 ; i <= n ; i++)

        scanf("%d",&v[i]);

    build(1,1,n);

    for(int i = n ; i >= 1 ; i--)

    {

        int pos = query(1,1,n,v[i]);

        sol[pos] = i;

        update(1,1,n,pos,0);

    }

    for(int i = 1 ; i <= n ; i++)

        printf("%d\n",sol[i]);

    return 0;

}
