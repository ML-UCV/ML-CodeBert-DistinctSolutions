#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;



ifstream f("dmin.in");

ofstream g("dmin.out");



const int Const = 104659;



inline int Modulus (int number){

    return number % Const;

}



inline double make_abs (double number){

    return (number < 0 ? -number : number);

}



vector < pair<int, double> > v[1505];

priority_queue < pair <int, double>, vector < pair <int, double> >, greater < pair <int, double> > > pq;



int n, m;

double dist[1505];

int sol[1505], sptSet[1505];



void dijkstra(){



    for(int i = 2; i <= n; ++i) dist[i] = 0x3f3f3f3f;



    sol[1] = 1;

    dist[1] = 0;

    sptSet[1] = 1;

    pq.push(make_pair(1, dist[1]));



    while(!pq.empty()){



        int u = pq.top().first;

        pq.pop();



        for(int i = 0; i < v[u].size(); ++i){



            int nod = v[u][i].first;

            double distance = v[u][i].second;



            if(dist[u] + distance < dist[nod] - 1e-8){

                dist[nod] = dist[u] + distance;

                sol[nod] = sol[u];

                if(!sptSet[nod])

                    pq.push(make_pair(nod, dist[nod])), sptSet[nod] = 1;



            }



            else if (make_abs(dist[nod] - dist[u] - distance) <= 1e-8){

                sol[nod] = Modulus(sol[nod] + sol[u]);

            }

        }

    }

}



int main (){

    f >> n >> m;

    for (int i = 1; i <= m; ++i){

        int x, y;

        double d;

        f >> x >> y >> d;

        v[x].push_back(make_pair(y,log(d)));

        v[y].push_back(make_pair(x,log(d)));

    }



    dijkstra();

    for(int i = 2; i <= n; ++i) g << sol[i] << ' ';

}
