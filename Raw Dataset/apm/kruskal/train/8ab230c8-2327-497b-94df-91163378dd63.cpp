#include<bits/stdc++.h>
using namespace std;

ifstream fin("apm.in");

ofstream fout("apm.out");



struct elem

{

    int sursa,destinatie,cost;

} v[400001];



elem ans[200002];

int dim[200002],tata[400002],n,m,costapm,k;



inline bool cmp(const elem &a,const elem &b)

{

    return a.cost<b.cost;

}



int tata_multime(int x)

{

    if(x!=tata[x])

        tata[x]=tata_multime(tata[x]);

    return tata[x];

}



void unire(int x,int y)

{

    x=tata_multime(x);

    y=tata_multime(y);

    if(dim[x]<=dim[y])

    {

        dim[y]+=dim[x];

        tata[x]=y;

    }

    else

    {

        dim[x]+=dim[y];

        tata[y]=x;

    }

}



int main()

{

    int i;

    fin>>n>>m;

    for(i=1; i<=m; i++)

        fin>>v[i].sursa>>v[i].destinatie>>v[i].cost;

    for(i=1; i<=n; i++)

    {

        dim[i]=1;

        tata[i]=i;

    }

    sort(v+1,v+m+1,cmp);

    for(i=1; i<=m&&k<n-1; i++)

    {

        if(tata_multime(v[i].sursa)!=tata_multime(v[i].destinatie))

        {

            unire(v[i].sursa,v[i].destinatie);

        costapm+=v[i].cost;

        ans[++k]=v[i];

        }

    }

    fout<<costapm<<'\n';

    fout<<n-1<<'\n';

    for(i=1; i<=k; i++)

        fout<<ans[i].sursa<<" "<<ans[i].destinatie<<'\n';

    return 0;

}
