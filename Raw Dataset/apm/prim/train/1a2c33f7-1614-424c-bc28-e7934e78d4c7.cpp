#include <bits/stdc++.h>


using namespace std;



ifstream f("apm.in");

ofstream g("apm.out");



priority_queue < pair <int,int> , vector < pair <int,int > > , greater < pair <int,int > > > q;

vector < pair <int,int > > v[200100];

int CT,n,viz[200100],cost_muchie[200100],tata[200100];



void prim (int nod_start)

{

    for(int i=1;i<=n;i++)cost_muchie[i]=INT_MAX/2;

    cost_muchie[nod_start]=0;

    q.push({0,nod_start});



    while(!q.empty())

    {

        int nod=q.top().second;

        int cost_muchie_nod=q.top().first;

        q.pop();



        if(viz[nod]==0)

        {

            viz[nod]=1;

            CT+=cost_muchie_nod;



            for(int i=0;i<v[nod].size();i++)

            {

                int vecin=v[nod][i].first;

                int cost_intre=v[nod][i].second;



                if(cost_muchie[vecin]>cost_intre && viz[vecin]==0)

                {

                    cost_muchie[vecin]=cost_intre;

                    q.push({cost_muchie[vecin],vecin});

                    tata[vecin]=nod;

                }

            }

        }

    }

}



int m,i,x,y,cost;



int main()

{

    f>>n>>m;

    for(i=1;i<=m;i++)

    {

        f>>x>>y>>cost;

        v[x].push_back({y,cost});

        v[y].push_back({x,cost});

    }



    prim(1);



    g<<CT<<'\n';

    g<<n-1<<'\n';

    for(i=1;i<=n;i++)

        if(tata[i]!=0)g<<i<<" "<<tata[i]<<'\n';

    return 0;

}
