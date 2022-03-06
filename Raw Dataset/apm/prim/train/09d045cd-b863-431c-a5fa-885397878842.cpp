#include <fstream>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

ifstream f("apm.in");

ofstream g("apm.out");





int n, m, s;

int d[200005], t[200005], viz[200005];

vector<pair<int,int>>graf[200005];



void read()

{

    f>>n>>m;

    for (int i=0;i<m;++i)

    {

        int x,y,c;

        f>>x>>y>>c;

        graf[x].push_back({y,c});

        graf[y].push_back({x,c});

    }

    for (int i=0;i<=n;++i)

    {

        d[i]=999999999;

        t[i]=0;

        viz[i]=0;

    }



}



void output()

{

    int cost = 0;

    for(int i=1; i<=n; i++)

        cost += d[i];



    g<<cost<<'\n'<<n-1<<'\n';



    for(int i=0; i<=n; i++)

        if(t[i]!=0)

            g<<t[i]<<" "<<i<<'\n';





}



int main()

{

    read();

    s = 1;

    d[s] = 0;

    priority_queue<pair<int,int>>Q;

    Q.push({-d[s],s});

    while (!Q.empty())

    {

        int nod = Q.top().second;

        viz[nod] = 1;

        Q.pop();

        for (pair<int,int> i : graf[nod])

        {

            int y = i.first;

            int j = i.second;

            if (viz[y] == 0 && d[y]>j)

            {

                t[y] = nod;

                d[y] = j;

                Q.push({-d[y],y});

            }

        }



    }



    output();



}
