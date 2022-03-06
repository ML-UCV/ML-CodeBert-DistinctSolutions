#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;



struct MUCHIE

{

    int u,v,c,sel;

};



vector<MUCHIE>v;

vector<int>t,h;



int FindSet(int x)

{

    while(x!=t[x])

        x=t[x];

    return x;

}



void UnionSet(int x,int y)

{

    if(h[x]==h[y])

    {

        t[y]=x;

        h[x]++;

    }

    else if(h[x]>h[y])

        t[y]=x;

    else

        t[x]=y;

}



bool cmp(MUCHIE a, MUCHIE b)

{

    return a.c<b.c;

}



int main()

{

    freopen("apm.in","r",stdin);

    freopen("apm.out","w",stdout);

    int n,m,i,k,tc,tu,tv;

    MUCHIE temp;

    scanf("%d%d",&n,&m);

    t.assign(n+1,0);

    h.assign(n+1,1);

    for(i=1;i<=n;i++)

        t[i]=i;

    for(i=1;i<=m;i++)

    {

        scanf("%d%d%d",&temp.u,&temp.v,&temp.c);

        temp.sel=0;

        v.push_back(temp);

    }

    sort(v.begin(),v.begin()+m,cmp);

    tc=k=0;

    for(i=0;i<m && k<n-1;i++)

    {

        tu=FindSet(v[i].u);

        tv=FindSet(v[i].v);

        if(tu!=tv)

        {

            UnionSet(tu,tv);

            k++;

            tc=tc+v[i].c;

            v[i].sel=1;

        }

    }

    printf("%d\n",tc);

    int nrsel=0;

    for(i=0;i<v.size();i++)

        if(v[i].sel)

            nrsel++;

    printf("%d\n",nrsel);

    for(i=0;i<v.size();i++)

        if(v[i].sel)

            printf("%d %d\n",v[i].u,v[i].v);

    return 0;

}
