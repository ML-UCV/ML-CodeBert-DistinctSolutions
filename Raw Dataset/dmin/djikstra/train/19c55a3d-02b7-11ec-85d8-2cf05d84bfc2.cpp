#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
#include <iostream>
#include <cmath>
using namespace std;



const int NMAX = 1507;

const int INF = 10000000000;

const int Mod = 104659;

const double EPS = 0.00000000001;



priority_queue< pair< double, int > > q;

double D[NMAX];

int Dp[NMAX], Viz[NMAX];

vector< pair< int, double > > v[NMAX];

int n, m;



int ok(double a, double b){

    if(a > b + EPS)

        return 1;

    if(b > a + EPS)

        return -1;

    return 0;

}



void Dijkstra(){

    for(int i = 2 ; i <= n ; ++ i)

        D[i] = INF;

    q.push(make_pair(0 , 1));

    while(! q.empty()){

        int Nod = q.top().second;

        q.pop();

        if(Viz[Nod] == 0){

            Viz[Nod] = 1;

            pair< int, double > it;

            for(int i = 0; i < v[Nod].size(); ++i){

                it = v[Nod][i];

                if(ok(D[it.first], D[Nod] + it.second) == 0){

                    Dp[it.first] += Dp[Nod];

                    Dp[it.first] %= Mod;

                }

                if(ok(D[it.first], D[Nod] + it.second) == 1){

                    Dp[it.first] = Dp[Nod] % Mod;

                    D[it.first] = D[Nod] + it.second;

                    q.push(make_pair(-D[it.first] , it.first));

                }

            }

        }

    }

}





int main(){

    freopen("dmin.in", "r", stdin);

    freopen("dmin.out", "w", stdout);

    scanf("%d %d", &n, &m);

    for(int i = 1; i <= m; ++i){

        int a, b;

        double c;

        scanf("%d %d %lf\n", &a, &b, &c);

        c = (double)log(c);

        v[a].push_back(make_pair(b, c));

        v[b].push_back(make_pair(a, c));

    }

    Dp[1] = 1;

    Dijkstra();

    for(int i = 2; i <= n; ++i)

        printf("%d ", Dp[i]);

    return 0;

}
