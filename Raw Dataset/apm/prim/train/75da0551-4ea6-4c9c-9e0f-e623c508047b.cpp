#include <iostream>
#include <fstream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <queue>
using namespace std;



ifstream in("apm.in");



ofstream out("apm.out");



const int INF = 100000000;



vector<int> d;



vector<int> tata;



vector <int> cost;



vector<int> viz;



vector<pair<int,int>>adiacenta[200000];



priority_queue< pair<int,int>, vector <pair<int,int>>, greater<pair<int,int>> > Q;





int n,m,i,s;



void Prim()

{

    d[s] = 0;

    Q.push(make_pair(0,s));



    while(!Q.empty())

    {

        int u = Q.top().second;

        viz[u] = 1;

        Q.pop();

        for (pair<int,int> e : adiacenta[u])

        {

            int vecin = e.first;

            int c = e.second;



            if (!viz[vecin] && c < cost[vecin])

            {



                cost[vecin] = c;

                Q.push(make_pair(cost[vecin], vecin));







                tata[vecin] = u;



            }



        }

    }

}



int main()

{

    in >> n >> m;

    d.resize(n+1);

    tata.resize(n+1);

    viz.resize(n+1);

    cost.resize(n+1);

    int x,y,c;

    for(i=0;i<m;i++)

    {

         in>>x>>y>>c;

        adiacenta[x].push_back(make_pair(y, c));

        adiacenta[y].push_back(make_pair(x, c));

    }

    s=1;





    for(int i=1;i<=n;i++)

    {

        cost[i] = INF;

        viz[i] = 0;

        tata[i] = -1;

    }



    Prim();





    int d_arbore = 0;

    for(int i=1;i<=n;i++)

    {

        if(i==s)

            continue;

        d_arbore += cost[i];

    }

    out << d_arbore << endl;

    out << n-1 << endl;

    for(int i=1;i<=n;i++)

    {

        if(i==s)

            continue;

        out << tata[i] << " " << i << '\n';

    }



}
