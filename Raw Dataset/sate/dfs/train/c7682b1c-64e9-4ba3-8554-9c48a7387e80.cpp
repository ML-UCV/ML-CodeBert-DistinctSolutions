#include <fstream>
#define N 30003
#include <vector>
#define oo 1e7
using namespace std;

int n,m,A,B,x,y,c;
int dist[N];
bool f[N];

vector<pair<int,int> > v[N]; //.first.second ,nod.cost

ifstream fin("sate.in");
ofstream fout("sate.out");

inline void DFS(const int & nod)
{
    f[nod] = 1;
    for(auto i : v[nod])
        if(!f[i.first] && dist[i.first] == 0)
        {
            dist[i.first] = dist[nod] + i.second;
            DFS(i.first);
        }
    f[nod] = 0;
}

int main()
{
    fin>>n>>m>>A>>B;

    while(m--)
    {
        fin>>x>>y>>c;
        v[min(x,y)].push_back(make_pair(max(x,y),c));
        v[max(x,y)].push_back(make_pair(min(x,y),-c));
    }

    DFS(A);
    fout<<dist[B];

    fin.close();
    fout.close();
    return 0;
}
