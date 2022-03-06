#include<fstream>


using namespace std;



typedef struct lista

{

    int info;

    lista * next;

} *nod;



nod a[222];

nod b[222];

int ctc[222];

int st[222];

bool viz[222];

int i,j,k,m,n,u,nr;





void dfs1(int x)

{

    viz[x]=1;

    for (nod r=a[x];r;r=r->next)

    {

        if (!viz[r->info]) dfs1(r->info);

    }

    st[++u]=x;

}





void dfs2(int x)

{

    viz[x]=0;

    ctc[x]=nr;

    for (nod r=b[x];r;r=r->next)

    {

        if (viz[r->info]) dfs2(r->info);

    }

}

int neg(int x)

{

   if (x>n) return x-n;

   return x+n;

}





void add(int x, nod &p)

{

    nod r=new lista;

    r->info=x;

    r->next=p;

    p=r;

}

ifstream cin("party.in");

ofstream cout("party.out");



int main()

{

    cin>>n>>m;

    while(m--)

    {

        int x,y,op;

        cin>>x>>y>>op;

        if (op==1) {y=neg(y);}

        if (op==2) {x=neg(x);}

        if (op==3) {x=neg(x); y=neg(y);}

        add(y,a[neg(x)]);

        add(x,a[neg(y)]);

        add(neg(x),b[y]);

        add(neg(y),b[x]);

    }

    for (i=1; i<=2*n; ++i)

        if (!viz[i]) dfs1(i);

    for (i=u; i>=1; --i)

        if (viz[st[i]])

                {

                 nr++;

                 ctc[st[i]]=nr;

                 dfs2(st[i]);

                }

    int sol[123];

    u=0;



    for (i=1; i<=n; ++i)

        if (ctc[i]>ctc[i+n]) sol[++u]=i;

    cout<<u<<"\n";

    for (i=1; i<=u; ++i) cout<<sol[i]<<"\n";







    return 0;

}
