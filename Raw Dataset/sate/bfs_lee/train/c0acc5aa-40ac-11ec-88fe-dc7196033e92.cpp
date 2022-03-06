
#include <fstream>
#include <vector>
#include <queue>
#define N 30005

using namespace std;
ifstream fin("sate.in");
ofstream fout("sate.out");

int n, m, x, y, viz[N], sol[N];
vector <pair<int, int>> muchii[N];
queue <int> C;


void Citire()
{
    int a, b, c, i;
    fin >> n >> m >> x >> y;
    for (i = 1; i <= m; i++)
    {
        fin >> a >> b >> c;
        muchii[a].push_back(make_pair(b, c));
        muchii[b].push_back(make_pair(a, -c));
    }
}

void BFS()
{
    int i,a;
    C.push(x);
    viz[x] = 1;
    while (C.empty() == 0)
    {
        a = C.front();
        C.pop();
        for(auto i:muchii[a])
            if (viz[i.first] == 0)
            {
                C.push(i.first);
                viz[i.first] = 1;
                sol[i.first] = sol[a] + i.second;
                if (i.first == y)
                {
                    fout << sol[i.first];
                    return;
                }

            }

    }
}


int main()
{
    Citire();
    BFS();
    return 0;
}

