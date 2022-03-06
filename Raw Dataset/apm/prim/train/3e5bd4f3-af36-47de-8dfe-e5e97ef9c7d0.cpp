#include<bits/stdc++.h>
using namespace std;



ifstream fin("apm.in");

ofstream fout("apm.out");



constexpr int NX = 200010;

constexpr int inf = 1010;

int N, M, cost;

int dist[NX], daddy[NX];

bool viz[NX];

typedef pair<int, int> Pair;

vector <Pair> V[NX];

priority_queue < Pair, vector < Pair >, greater < Pair >> pq;



int main()

{

    fin>>N>>M;

    int x, y, z;

    for(int i=1; i<=M; ++i)

    {

        fin>>x>>y>>z;

        V[x].push_back(make_pair(y, z));

        V[y].push_back(make_pair(x, z));

    }



    for(int i=1; i<=N; ++i)

    {

        dist[i]=inf;

        daddy[i]=-1;

    }





    pq.push(make_pair(0, 1));

    dist[1] = 0;

    daddy[1] = 0;

    while(!pq.empty())

    {

        int prim = pq.top().second;

        pq.pop();

        if(viz[prim]==0)

        {

            viz[prim] = 1;

            cost+=dist[prim];

            for(auto &i : V[prim])

            {

                int nod=i.first;

                if(viz[nod]==0 && i.second < dist[nod])

                {



                    dist[nod]=i.second;

                    pq.push(make_pair(dist[nod], nod));

                    daddy[nod]=prim;

                }



            }

        }

    }



    fout<<cost<<"\n"<<N-1<<"\n";

    for(int i=2; i<=N; ++i)

        fout<<i<<" "<<daddy[i]<<"\n";

    return 0;

}
