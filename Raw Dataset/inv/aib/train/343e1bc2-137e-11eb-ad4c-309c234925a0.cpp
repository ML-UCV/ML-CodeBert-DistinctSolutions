#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

ifstream cin("inv.in");

ofstream cout("inv.out");

const int lim=1e5+3;

const int mod=9917;

int v[lim],f[lim];

int tree[lim];

int n;

vector<int> upd;

void sum(int &a,int b)

{

    a+=b;

    if(a>=mod)

        a-=mod;

}

void add(int k,int x)

{

    while(k<=n)

    {

        sum(tree[k],x);

        k+=k&-k;

    }

}

int cnt(int k)

{

    int rez=0;

    while(k>0)

    {

        sum(rez,tree[k]);

        k-=k&-k;

    }

    return rez;

}

bool ordine(int a,int b)

{return f[a]>f[b];}

int main()

{

    cin>>n;

    for(int i=1;i<=n;++i)

    {

        cin>>f[i];

        v[i]=i;

    }

    sort(v+1,v+n+1,ordine);

    int ans=0;

    sum(ans,cnt(v[1]));

    upd.push_back(v[1]);

    for(int i=2;i<=n;++i)

    {

        if(f[v[i]]!=f[v[i-1]])

        {

            for(int j=0;j<upd.size();++j)

                add(upd[j],1);

            upd.clear();

        }

        sum(ans,cnt(v[i]));

        upd.push_back(v[i]);

    }

    cout<<ans<<'\n';

    return 0;

}
