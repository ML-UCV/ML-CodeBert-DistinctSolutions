#include <fstream>
#include <cmath>
#include <vector>
#include <queue>
#include <iomanip>
#include <algorithm>
using namespace std;



ifstream fin("dmin.in");

ofstream fout("dmin.out");



const int NMAX = 1505, MOD = 104659;

const double EPS = 1e-8;



int DP[NMAX], N, M, X, Y, C;

double Dist[NMAX];

vector<pair<int, double> > G[NMAX];



struct Comp

{

    bool operator() (const pair<int, double> A, const pair<int, double> &B) const

    {

        return A.second > B.second;

    }

};



priority_queue<pair<int, double>, vector<pair<int, double> >, Comp> Q;



void Go_Dijkstra()

{

    for(int i = 1; i <= N; ++ i) Dist[i] = 999999999;



    Dist[1] = 0;

    DP[1] = 1;

    Q.push(make_pair(1, 0.0));



    while(!Q.empty())

    {

        double Cost = Q.top().second;

        int Node = Q.top().first;

        Q.pop();



        if(Cost > Dist[Node]) continue;



        for(vector<pair<int, double> > :: iterator it = G[Node].begin(); it != G[Node].end(); ++ it)

        {

            if(Cost + it -> second < Dist[it -> first] || fabs(Cost + it -> second - Dist[it -> first]) < EPS)

            {

                if(Cost + it -> second <= Dist[it -> first] - EPS)

                {

                    Dist[it -> first] = Cost + it -> second;

                    DP[it -> first] = 0;

                    Q.push(make_pair(it -> first, Dist[it -> first]));

                }

                DP[it -> first] = (DP[it -> first] + DP[Node]) % MOD;

            }

        }

    }



    for(int i = 2; i <= N; ++ i)

        fout << DP[i] << " ";

}



int main()

{

    fin >> N >> M;

    for(int i = 1; i <= M; ++ i)

    {

        fin >> X >> Y >> C;

        G[X].push_back(make_pair(Y, log(1.0 * C)));

        G[Y].push_back(make_pair(X, log(1.0 * C)));

    }



    Go_Dijkstra();



    return 0;

}
