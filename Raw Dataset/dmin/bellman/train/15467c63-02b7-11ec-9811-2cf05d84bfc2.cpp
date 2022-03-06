#include <fstream>
#include <queue>
#include <cmath>
#include <algorithm>
#include <vector>


using namespace std;



ifstream fin("dmin.in");

ofstream fout("dmin.out");



const int MOD = 104659;

const double eps = 1e-10;

const double INF = 100000.0;



int N, M;

int dp[1505], dpant[1505];

double cost[1505];

vector<pair<int, double> > V[1505];

queue<int> Q;

bool inQ[1505];



void bellman()

{

    for (int i = 1; i <= N; ++i)

        cost[i] = INF;

    cost[1] = 0.0;

    dp[1] = 1;

    Q.push(1);

    inQ[1] = true;



    while (!Q.empty())

    {

        int now = Q.front();

        Q.pop();

        inQ[now] = false;



        dp[now] = dp[now] - dpant[now];

        dpant[now] = dp[now];



        for (vector<pair<int, double> >::iterator it = V[now].begin(); it != V[now].end(); ++it)

        {

            int vecin = it->first;

            double cvecin = it->second;

            if (cost[now] + it->second - cost[it->first] <= -eps)

            {

                cost[it->first] = cost[now] + it->second;

                dp[it->first] = dp[now];

                dpant[it->first] = 0;

                if (!inQ[it->first])

                {

                    Q.push(it->first);

                    inQ[it->first] = true;

                }

            }

            else if (fabs(cost[now] + it->second - cost[it->first]) < eps)

            {

                dp[it->first] = (dp[it->first] + dp[now]) % MOD;

                if (!inQ[it->first])

                {

                    Q.push(it->first);

                    inQ[it->first] = true;

                }

            }

        }

    }

}



int main()

{

    fin >> N >> M;

    for (int i = 1, nod1, nod2, c; i <= M; ++i)

    {

        fin >> nod1 >> nod2 >> c;

        double newc = log(double(c));

        V[nod1].push_back(make_pair(nod2, newc));

        V[nod2].push_back(make_pair(nod1, newc));

    }



    bellman();



    for (int i = 2; i <= N; ++i)

        fout << dp[i] << ' ';



    fin.close();

    fout.close();

    return 0;

}
