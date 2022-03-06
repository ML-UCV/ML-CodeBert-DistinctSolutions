#include <fstream>
#include <vector>
#include <set>


using namespace std;



ifstream fin ("apm.in");

ofstream fout ("apm.out");



const int INFINIT = 1005;

const int NMAX = 200005;



vector < vector < pair < int, int > > > costuri(NMAX);

vector < int > vx;

vector < int > vy;

int tati[NMAX], N, M;

bool vizitat[NMAX];

int dist[NMAX];

long long cost_minim;

int nod_start = -1;



set < pair < int, int > > heap;



void init()

{

    for(int i = 0; i < NMAX; i++)

        dist[i] = INFINIT;

}



void citire()

{

    fin >> N >> M;

    int x, y, cost;

    int cost_min = 1005;

    for(int i = 0; i < M; i++)

    {

        fin >> x >> y >> cost;

        pair < int, int > pair_1 = make_pair(y, cost);

        pair < int, int > pair_2 = make_pair(x, cost);

        costuri[x].push_back(pair_1);

        costuri[y].push_back(pair_2);

        if(cost < cost_min)

        {

            cost_min = cost;

            nod_start = x;

        }

    }

    init();

}



void Prim()

{

    for(unsigned int i = 0; i < costuri[nod_start].size(); i++)

    {

        tati[costuri[nod_start][i].first] = nod_start;

        heap.insert( {costuri[nod_start][i].second, costuri[nod_start][i].first} );

        dist[costuri[nod_start][i].first] = costuri[nod_start][i].second;

    }

    vizitat[nod_start] = 1;



    while(!heap.empty())

    {

        int mini = heap.begin() -> second;

        int cost = heap.begin() -> first;

        heap.erase(heap.begin());



        if(vizitat[mini])

            continue;

        cost_minim += cost;

        vizitat[mini] = 1;

        vx.push_back(tati[mini]); vy.push_back(mini);

        for(unsigned int k = 0; k < costuri[mini].size(); k++)

            if(!vizitat[costuri[mini][k].first])

            {

                if(costuri[mini][k].second < dist[costuri[mini][k].first])

                {

                    dist[costuri[mini][k].first] = costuri[mini][k].second;

                    tati[costuri[mini][k].first] = mini;

                }

                heap.insert( {costuri[mini][k].second, costuri[mini][k].first} );

            }

    }

}



void afisare()

{

    fout << cost_minim << '\n';

    fout << N - 1 << '\n';

    for(int i = 0; i < N - 1; i++)

        fout << vx[i] << ' ' << vy[i] << '\n';

}



int main()

{

    citire();

    Prim();

    afisare();

    return 0;

}
