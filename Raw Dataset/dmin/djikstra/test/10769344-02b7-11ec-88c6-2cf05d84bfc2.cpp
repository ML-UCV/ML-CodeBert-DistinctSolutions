#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

ifstream in("dmin.in");
ofstream out("dmin.out");





const int N_max = 15005;

double dmin[N_max];

int sol[N_max];

bool viz[N_max];

class cmp
{
    public:
        bool operator () (int x, int y)
        {
            return dmin[x] > dmin[y];
        }
};

priority_queue < int, vector <int>, cmp > H;

vector < pair <int, double> > graph[N_max];

int N, M;

void citire()
{
    int x, y;
    double c, cost;

    in >> N >> M;

    for(int i = 1; i <= M; i++)
    {
        in >> x >> y >> c;

        cost = log10(c);


        graph[x].push_back(make_pair(y, cost));
        graph[y].push_back(make_pair(x, cost));
    }
}

void dijkstra(int node)
{
    int i, x, y;
    double cost;

    for(i = 1; i <= N; i++) dmin[i] = 2e9;


    H.push(node);
    dmin[1] = 0;

    sol[node] = 1;
    viz[node] = true;

    while(!H.empty())
    {
        x = H.top();
        H.pop();

        for(i = 0; i < graph[x].size(); i++)
        {
            y = graph[x][i].first;

            cost = graph[x][i].second;

            if(dmin[y] - dmin[x] - cost > 0.0000000001)
            {
                dmin[y] = dmin[x] + cost;

                sol[y] = sol[x];

                if(!viz[y])
                {
                    H.push(y);
                    viz[y] = true;
                }
            }
            else
                if(dmin[x] + cost - dmin[y] <= 0.0000000001)
                {
                    sol[y] += sol[x];

                    sol[y] %= 104659;
                }
        }
    }
}

void write()
{
    for(int i = 2; i <= N; i++) out << sol[i] << " ";
}

int main()
{
    citire();

    dijkstra(1);

    write();

    return 0;
}
