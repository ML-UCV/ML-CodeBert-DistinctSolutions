#include <fstream>
#include <cmath>
#include <queue>
#include <vector>






using namespace std;



ifstream fin("dmin.in");

ofstream fout("dmin.out");



const int NMax = 1500, oo = 1e9, MOD = 104659;

const double E = 1e-8;



int N, M, DP[NMax + 5];



vector <pair<int, double> > G[NMax + 5];

priority_queue <pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > Q;



double D[NMax + 5];



void Dijkstra(int Nod)

{

    for(int i = 2; i <= N; i++)

        D[i] = oo;



    Q.push({0, 1}), DP[1] = 1;



    while(!Q.empty())

    {

        Nod = Q.top().second;



        for(auto Vecin : G[Nod])

        {

            int A = Vecin.first;

            double C = Vecin.second;



            if(D[A] == oo)

                D[A] = D[Nod] + C, Q.push({D[A], A});

            else

            {

                if(fabs(D[A] + C - D[Nod]) < E)

                    DP[Nod] = (DP[Nod] + DP[A]) % MOD;

            }

        }

        Q.pop();

    }

}



int main()

{

    fin >> N >> M;



    for(int i = 1, a, b; i <= M; i++)

    {

        double c;

        fin >> a >> b >> c; c = log2(c);



        G[a].push_back({b, c});

        G[b].push_back({a, c});

    }

    Dijkstra(1);



    for(int i = 2; i <= N; i++)

        fout << DP[i] << " ";



    fout << '\n';



    fin.close();

    fout.close();



    return 0;

}
