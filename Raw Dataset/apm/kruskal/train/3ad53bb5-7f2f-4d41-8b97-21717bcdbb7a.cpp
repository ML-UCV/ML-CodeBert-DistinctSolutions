#include <bits/stdc++.h>


using namespace std;

ifstream f("apm.in");

ofstream g("apm.out");

typedef long long ll;

typedef pair<int,int> pi;

const int dim=4e5+2;

ll t,T,n,m,a,b,c,tata[dim],h[dim],R[dim],rmq[dim][20];

ll ans;

bitset < dim > there,viz;



pi father[dim];



struct go

{

    ll v1,c,idx;

};



struct no

{

    ll v1,v2,c,idx;

}B[dim];

vector < pi > OP;

vector < go > V[dim];

vector < go > A(dim);



bool cmp(no X,no Y)

{

    if(X.c<Y.c) return true;

    else

    if(X.c==Y.c)

    {

        if(X.v1<Y.v1) return true;

        else return false;

    }

    else return false;

}



void Union(int x,int y)

{

    if(h[x]>h[y]) tata[y]=x;

    else

    {

        tata[x]=y;

        if(h[x]==h[y]) h[y]++;

    }

}



int Find(int v)

{

    int r=v;

    while(tata[r]!=r) r=tata[r];

    int y=v;

    while(y!=r)

    {

        t=tata[y];

        tata[y]=r;

        y=t;

    }

    return r;

}



void Built()

{

    for(int i=1;i<=n;i++)

    {

        tata[i]=i;

        h[i]=0;

    }

    sort(B+1,B+m+1,cmp);



    for(int i=1;i<=m;i++)

    {

        a=B[i].v1; b=B[i].v2; c=B[i].c;

        if(Find(a)!=Find(b))

        {

            Union(Find(a),Find(b));

            OP.push_back({a,b});

            there[B[i].idx]=1;

            ans+=c;

        }

    }

    father[1]={0,0};

}
int main()

{

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    f>>n>>m;

    for(int i=1;i<=m;i++)

    {

        f>>a>>b>>c;

        V[a].push_back({b,c,i});

        V[b].push_back({a,c,i});

        A[i]={a,b,c};

        B[i]={a,b,c,i};

    }

    Built();



    g<<ans<<'\n';

    g<<n-1<<'\n';

    for(int i=0;i<OP.size();i++) g<<OP[i].first<<' '<<OP[i].second<<'\n';

    return 0;

}
