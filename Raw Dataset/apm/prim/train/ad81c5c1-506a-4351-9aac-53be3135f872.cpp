#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <utility>
#include <list>
#include <queue>
#include <functional>
using namespace std;



ifstream fin("apm.in");

ofstream fout("apm.out");



int inf = 100000;

priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;

int n,m;

int tata[200001],viz[200001],key[200001];

list <pair<int,int>> ad[200001];

int main()

{

    fin >> n >> m;

    for( int i = 1; i <= m ; i++)

    {

        int a,b,c;

        fin >> a >> b >> c;

        ad[a].push_back(make_pair(b,c));

        ad[b].push_back(make_pair(a,c));

    }



    int s = 1, cost = 0;

    for(int i = 1; i <= n; i ++)

       {



           tata[i] = 0;

           viz[i] = 1;

           key[i] = inf;

       }

    q.push(make_pair(0,s));

    key[s] = 0;

    while(!q.empty())

    {



        pair <int,int> least = q.top();

        int node = least.second;



        q.pop();



        if(viz[node] == 0)

            continue;

        viz[node] = 0;

        cost += least.first;



        for(auto &edge: ad[node])

        {

           if(viz[edge.first] && edge.second < key[edge.first])

           {

               key[edge.first] = edge.second;

               tata[edge.first] = node;

               q.push(make_pair(key[edge.first],edge.first));

           }

        }

    }

    fout<<cost<<"\n"<< (n - 1) << "\n";

    for(int i = 1; i <= n; i ++)

        if( i != s)

        fout << i << " " << tata[i] << "\n";

    return 0;

}
