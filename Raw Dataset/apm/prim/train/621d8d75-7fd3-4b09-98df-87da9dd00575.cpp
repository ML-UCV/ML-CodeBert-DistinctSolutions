#include <bits/stdc++.h>


using namespace std;



ifstream in("apm.in");

ofstream out("apm.out");



pair <int,int> h[400001];



vector < pair <int,int> > g[200001];



int n,cost[200001],fr[200001],parent[200001];



int father(int x)

{

    return x/2;

}



int lson(int x)

{

    return 2*x;

}



int rson(int x)

{

    return 2*x+1;

}



void sift(int k)

{

    int son=lson(k);

    while(son!=0)

    {

        son=lson(k);

        if(son<=n)

        {

            if(son+1<=n && h[son+1].first<h[son].first)

                son++;

            if(h[son].first<h[k].first)

            {

                swap(h[son],h[k]);

                k=son;

            }

            else

                son=0;

        }

        else

            son=0;

    }

}



void percolate(int k)

{

    pair <int,int> aux=h[k];

    while(k>1 && h[father(k)].first>aux.first)

    {

        h[k]=h[father(k)];

        k=father(k);

    }

    h[k]=aux;

}



void cut(int k)

{

    h[k]=h[n];

    n--;

    if(k>1 && h[k].first<h[father(k)].first)

        percolate(k);

    else

        sift(k);

}



void h_insert(pair <int,int> val)

{

    h[++n]=val;

    percolate(n);

}



int main()

{

    int p,m,i,j,x,y,c,s=0;

    in>>p>>m;

    for(i=1;i<=m;i++)

    {

        in>>x>>y>>c;

        g[x].push_back({y,c});

        g[y].push_back({x,c});

        cost[i]=1e9;

    }

    cost[1]=0;

    h_insert({0,1});

    while(n>0)

    {

        x=h[1].second;

        cut(1);

        if(fr[x]==0)

        {

            fr[x]=1;

            for(i=0;i<g[x].size();i++)

            {

                y=g[x][i].first;

                c=g[x][i].second;

                if(fr[y]==0 && c<cost[y])

                {

                    cost[y]=c;

                    h_insert({c,y});

                    parent[y]=x;

                }

            }

        }

    }

    for(i=1;i<=p;i++)

        s=s+cost[i];

    out<<s<<"\n"<<p-1<<"\n";

    for(i=2;i<=p;i++)

        out<<parent[i]<<" "<<i<<"\n";

    return 0;

}
