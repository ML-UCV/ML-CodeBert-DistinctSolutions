#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#define vector std::vector
#define pair std::pair
#define pb push_back
#define citire std::ifstream
#define afisare std::ofstream
#define queue std::queue

citire in("sate.in");
afisare out("sate.out");

class Graf{
    int V;
    vector< pair<int, int> > *adj;
public:
    Graf(int n);
    void addEdge(int i,int j, int d);
    void Solve(int x, int y);
};

Graf::Graf(int n){
    V = n;
    adj = new vector<pair<int,int>>[n+1];
}

void Graf::addEdge(int i, int j, int d){
    adj[i].pb({j,d});
    adj[j].pb({i,-d});
}

void Graf::Solve(int x, int y)
{
    int dist[30005];
    bool viz[30005];
    int s, next, distanta;
    queue<int> coada;
    coada.push(x);
    viz[x] = true;
    while (!coada.empty())
    {
        s = coada.front();
        coada.pop();
        for (auto rel : adj[s])
        {
            next = rel.first;
            distanta = rel.second;
            if (!viz[next])
            {
                viz[next] = true;
                dist[next] = dist[s] + distanta;
                coada.push(next);
                if (next == y)
                {
                    out << dist[y] << "\n";
                    return;
                }
            }
        }
    }
}

int main()
{
    int n, m, x, y;
    in >> n >> m >> x >> y;
    Graf graf = Graf(n);
    while(m--)
    {
        int i, j, d;
        in >> i >> j >> d;
        graf.addEdge(i,j,d);

    }
    graf.Solve(x,y);
    in.close();
    out.close();
    return 0;
}
