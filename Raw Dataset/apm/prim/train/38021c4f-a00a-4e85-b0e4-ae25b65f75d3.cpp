#include <bits/stdc++.h>


using namespace std;

ifstream f("apm.in");

ofstream g("apm.out");

const int dim=2e5+10;

typedef long long ll;

typedef pair<int,int> pi;

int t,n,m,a,b,c,cost;



vector < int > T(dim,0),viz(dim,0);

vector < pi > V[dim];



struct edge

{

    int st,dr,val;

};



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



int main()

{

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

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



    return 0;

}
