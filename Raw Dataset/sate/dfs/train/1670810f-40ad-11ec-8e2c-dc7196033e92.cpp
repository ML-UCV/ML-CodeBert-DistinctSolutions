#include <fstream>
#include <vector>

#define N 30005

using namespace std;

ifstream fin ("sate.in");
ofstream fout("sate.out");

int dist[N];
vector <pair <int, int> > G[N];
bool viz[N];

inline void DFS(const int &nod)
{
    viz[nod] = 1;
    for(auto i : G[nod])
        if(!viz[i.first])
        {
            dist[i.first] = dist[nod] + i.second;
            DFS(i.first);
        }
}

int main()
{
    int n, m, X, Y;
    fin >> n >> m >> X >> Y;
    for(int i = 1, x, y, c; i <= m; ++i)
    {
        fin >> x >> y >> c;
        G[x].push_back(make_pair(y, c));
        G[y].push_back(make_pair(x, -c));
    }
    fin.close();

    DFS(X);
    fout << dist[Y];
    fout.close();
    return 0;
}
