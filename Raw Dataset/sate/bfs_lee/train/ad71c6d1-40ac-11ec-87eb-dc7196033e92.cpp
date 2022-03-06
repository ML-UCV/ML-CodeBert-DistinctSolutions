#include <fstream>
#include <vector>
#include <queue>
#include <cmath>
 
using namespace std;
 
ifstream fin  ("sate.in");
ofstream fout ("sate.out");
 
const int NMAX = 30005;
 
int N, M, x, y;
bool vizitat[NMAX]; int dist[NMAX];
vector < vector < pair < int, int > > > edges(NMAX);
 
void read()
{
    fin >> N >> M >> x >> y;
    int a, b, c;
    for(int i = 0; i < M; i++)
    {
        fin >> a >> b >> c;
        edges[a].push_back({b, c});
        edges[b].push_back({a, c});
    }
}
 
void BFS(int nod)
{
    queue < int > coada;
    coada.push(nod);
    vizitat[nod] = true;
    
    while(!coada.empty())
    {
        int next = coada.front();
        coada.pop();
        
        for(unsigned int i = 0; i < edges[next].size(); i++)
        {
            int vecin = edges[next][i].first;
            int cost = edges[next][i].second;
            
            if(!vizitat[vecin])
            {
                dist[vecin] = dist[next] + pow(-1, (vecin < next)) * cost;
                coada.push(vecin);
                vizitat[vecin] = true;
            }
        }
    }
}
 
int main()
{
    read();
    BFS(x);
    fout << dist[y] << '\n';
    return 0;
}
