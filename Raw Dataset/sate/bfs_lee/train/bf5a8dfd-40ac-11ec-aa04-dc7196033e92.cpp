#include <fstream>
#include <iostream>
#include <vector>
#include <queue>
#define N_MAX 30005

using namespace std;

ifstream f("sate.in");
ofstream g("sate.out");

int N, M , X, Y, drum[N_MAX];
bool viz[N_MAX];

vector < pair <int, int> > v[N_MAX];
queue <int> q;


void bfs()
{
    int aux, i;

    while(!q.empty())
    {
        aux = q.front();
        q.pop();

        for(i = 0 ; i < v[aux].size(); i++)
        {
            if(viz[v[aux][i].first] == false || drum[aux] + v[aux][i].second < drum[v[aux][i].first])
            {
                viz[v[aux][i].first] = true;
                drum[v[aux][i].first] = drum[aux] + v[aux][i].second;
                q.push(v[aux][i].first);
            }
        }
    }
}

int main()
{
    f>>N>>M>>X>>Y;

    int i, sat1, sat2, dist;

    for(i = 1; i <= M; i++)
    {
        f>>sat1>>sat2>>dist;

        v[sat1].push_back(make_pair(sat2, dist));
        v[sat2].push_back(make_pair(sat1, -dist));
    }

    q.push(X);
    viz[X] = true;

    bfs();

    g<<drum[Y];
}
