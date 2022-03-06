#include <fstream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <iomanip>
using namespace std;



int ANS[1505],viz[1505];

double dist[1505];

int n,m,x,y,c;

vector<pair<int,double> > G[1505];

queue<int> q;



void bf(){

    for(int i = 1; i <= n; ++i)

        dist[i] = 10000000.0;



    dist[1] = 0;

    ANS[1] = 1;

    q.push(1);

    viz[1] = 1;

    while(!q.empty()){

        int nod = q.front();

        q.pop();

        for(int i = 0; i < G[nod].size(); ++i){

            if(abs(dist[G[nod][i].first] - dist[nod] - G[nod][i].second) <= 0.0000001){

                ANS[G[nod][i].first] = (ANS[G[nod][i].first] + ANS[nod] % 104659) % 104659;

            }

            if(dist[G[nod][i].first] - dist[nod] - G[nod][i].second > 0.0000001){

                dist[G[nod][i].first] = dist[nod] + G[nod][i].second;

                ANS[G[nod][i].first] = ANS[nod];

                if(viz[G[nod][i].first] == 0){

                    q.push(G[nod][i].first);

                    viz[G[nod][i].first] = 1;

                }

            }

        }

    }

    ofstream g("dmin.out");

    for(int i = 2; i <= n; ++i){

        g << ANS[i] % 104659 <<' ';

    }

    g.close();

}

int main()

{

    ifstream f("dmin.in");





    f >> n >> m;

    for(int i = 1; i <= m; ++i){

        f >> x >> y >> c;

        double w = log(c);

        G[x].push_back(make_pair(y,w));

        G[y].push_back(make_pair(x,w));

    }



    bf();



    f.close();



    return 0;

}
