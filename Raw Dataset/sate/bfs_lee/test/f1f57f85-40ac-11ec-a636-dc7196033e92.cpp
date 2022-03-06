#include <fstream>
#include <vector>
#include <bitset>
using namespace std;

#define FILE_NAME "sate"
ifstream in (FILE_NAME".in");
ofstream out(FILE_NAME".out");

constexpr int MAX_NODES = 30000 + 4;
vector < pair < int, int > > G[MAX_NODES];
bitset < MAX_NODES > Viz;
int N, M, X, Y;

vector < pair < int, int > > Q(2 * MAX_NODES);
int Lee()
{
    Q.push_back(make_pair(X, 0));
    Viz[X] = true;
    int nod, dist;
    unsigned p = 0;
    while(p < Q.size())
    {
        nod = Q[p].first;
        dist = Q[p].second;
        ++p;

        for(auto next : G[nod])
            if(!Viz[next.first])
            {
                if(next.first == Y)
                    return dist + next.second;

                Viz[next.first] = true;
                Q.push_back(make_pair(next.first, next.second + dist));
            }
    }
    return 0;
}

int main()
{
    in >> N >> M >> X >> Y;

    int a, b, c;
    while(M--)
    {
        in >> a >> b >> c;
        if(a < b)
        {
            G[a].push_back(make_pair(b, c));
            G[b].push_back(make_pair(a, -c));
        }
        else
        {
            G[a].push_back(make_pair(b, -c));
            G[b].push_back(make_pair(a, c));
        }
    }

    out << abs(Lee());

    return 0;
}
