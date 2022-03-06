#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <vector>
#include <queue>


using namespace std;

ifstream fin("apm.in");

ofstream fout("apm.out");

int t[200010], n, m, cost;

vector < pair<int,int> > a[200010], rez;

priority_queue< pair<int, pair<int,int> >, vector<pair<int, pair<int,int> > >, greater<pair<int, pair<int,int> > > >pq;

pair< int, pair<int,int> >x;



int main()

{

    int i, j, k;

    fin>>n>>m;

    for(k=1; k<=m; k++)

    {

        fin>>i>>j>>cost;

        a[i].push_back({cost,j});

        a[j].push_back({cost,i});

    }

    for(auto it:a[1])

    {

        pq.push( {it.first, {1, it.second}} );

    }

    cost=0;

    t[1]=1;

    while(pq.empty()==0)

    {

        x = pq.top();

        pq.pop();

        if( t[x.second.second]==0 )

        {

            t[x.second.second] = x.second.first;

            cost = cost + x.first;

            rez.push_back({x.second.first, x.second.second});

            for(auto it: a[x.second.second])

            {



                    pq.push( {it.first, {x.second.second, it.second}} );

            }

        }

    }

    t[1]=0;

    fout<<cost<<'\n';

    fout<<n-1<<'\n';

    for(auto it: rez)

        fout<<it.first<<" "<<it.second<<'\n';



    fin.close();

    fout.close();

    return 0;

}
