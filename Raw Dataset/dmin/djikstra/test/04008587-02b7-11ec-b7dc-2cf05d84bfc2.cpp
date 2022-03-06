#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <set>


using namespace std;



ifstream fin("dmin.in");

ofstream fout("dmin.out");



const int MOD = 104659;

const int NMAX = 1510;

const double EPS = 1e-10;

const double INF = (1<<25);



int n, m;

double dist[NMAX];

int nrDrum[NMAX];

vector<pair<int, double>> G[NMAX];



void Dijkstra()

{

    for(int i = 2; i <= n; i++)

        dist[i] = INF;

    set<pair<int, double>> Q;

    Q.insert(make_pair(0, 1));

    nrDrum[1] = 1;

    while(!Q.empty())

    {

        int node = Q.begin()->second;

        double d = Q.begin()->first;

        Q.erase(Q.begin());

        for(auto it : G[node])

        {

            int to = it.first;

            double cost = it.second;

            if(dist[to] > dist[node] + cost + EPS)

            {

                if(abs(dist[to] - INF) > EPS)

                    Q.erase(Q.find(make_pair(dist[to], to)));

                dist[to] = dist[node] + cost;

                nrDrum[to] = nrDrum[node] % MOD;

                Q.insert(make_pair(dist[to], to));

            }

            else if(abs(dist[to] - cost - dist[node]) <= EPS)

                nrDrum[to] = (nrDrum[to] + nrDrum[node]) % MOD;

        }

    }



}



int main()

{

    fin>>n>>m;

    for(int i = 1; i <= m; i++)

    {

        int to, from, cost;

        fin>>from>>to>>cost;

        double c = log(cost);

        G[to].push_back(make_pair(from, c));

        G[from].push_back(make_pair(to, c));

    }

    Dijkstra();

    for(int i = 2; i <= n; i++)

        fout<<nrDrum[i]<<' ';

    return 0;

}
