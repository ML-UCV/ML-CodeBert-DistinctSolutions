#include <bits/stdc++.h>


using namespace std;

ifstream f("apm.in");

ofstream g("apm.out");

const int dim=2e5+10;

typedef long long ll;

typedef pair<int,int> pi;

int t,n,m,a,b,c,cost,h[dim];



vector < int > T(dim,0),viz(dim,0);

vector < pi > V[dim],Muchii;



struct edge

{

    int st,dr,val;

};



vector < edge > A;



struct cmp

{

    bool operator()(edge X,edge Y)

    {

        if(X.val > Y.val)

            return 1;

        else

        {



            if(X.val==Y.val)

                return (X.st<Y.st);

            else

                return 0;

        }

    }

};



priority_queue < edge,vector < edge >,cmp > minheap;



void Solve1()

{

    f>>n>>m;

    for(int i=1;i<=m;i++)

    {

        f>>a>>b>>c;

        V[a].push_back({b,c});

        V[b].push_back({a,c});

    }

        for(pi x:V[1])

        minheap.push({1,x.first,x.second});



    int cnt=0;

    viz[1]=1;

    while(cnt<n)

    {

        bool stop=0;

        int nod;

        while(!minheap.empty()&&!stop)

        {

            int st=minheap.top().st;

            int dr=minheap.top().dr;

            int val=minheap.top().val;

            minheap.pop();

            if(viz[st]==0||viz[dr]==0)

            {

                cost+=val;

                T[dr]=st;

                viz[st]=1;

                viz[dr]=1;

                nod=dr;

                stop=1;

            }

        }

        cnt++;

        for(pi x:V[nod] )

           if(!viz[x.first])

              minheap.push({nod,x.first,x.second});

    }

    g<<cost<<'\n'<<n-1<<'\n';

    for(int i=2;i<=n;i++)

        g<<i<<' '<<T[i]<<'\n';

}





void Union(int x,int y)

{

    if(h[x]<h[y]) T[x]=y;

    else

    {

        if(h[x]==h[y]) h[x]++;

        T[y]=x;

    }

}



int Find(int x)

{

    int r=x;

    while(T[r]!=r) r=T[r];

    int y=x;

    while(y!=r)

    {

        int aux=T[y];

        T[y]=r;

        y=aux;

    }

    return r;

}



void Solve2()

{

    f>>n>>m;

    for(int i=1;i<=m;i++)

    {

        f>>a>>b>>c;

        A.push_back({a,b,c});

    }

    sort(A.begin(),A.end(),

         [&](edge X,edge Y)->bool

    {

        return (X.val<Y.val);

    });

    for(int i=1;i<=n;i++)

    {

        T[i]=i;

        h[i]=0;

    }

    for(edge x:A)

    {

        int st=x.st,dr=x.dr,val=x.val;

        int a=Find(st),b=Find(dr);

        if(a!=b)

        {

            Union(a,b);

            Muchii.push_back({st,dr});

            cost+=val;

        }

    }

    g<<cost<<'\n'<<n-1<<'\n';

    for(pi x:Muchii)

        g<<x.first<<' '<<x.second<<'\n';



}



int main()

{

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    Solve2();



    return 0;

}
