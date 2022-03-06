#include <iostream>
#include <queue>
#include <vector>
#include <fstream>

using namespace std;
vector <pair <int, int> > l[30001];
queue <int> q;
int n, m, x, y, d[30001], viz[30001];

int main()
{
    ifstream fin("sate.in");
    ofstream fout("sate.out");

    fin >> n >> m >> x >> y;
    int i,j,k,dist;

    for (i = 0; i < m; i++)
    {
        fin >> j >> k >> dist;
        l[j].push_back({k, dist});
        l[k].push_back({j, -dist});
    }

    q.push(x);
    viz[x] = 1;

    while (!q.empty())
    {
        int nod = q.front();
        q.pop();

        for (i = 0; i < l[nod].size(); i++)
        {
            j = l[nod][i].first;
            k = l[nod][i].second;
            if (viz[j] == 0)
            {
                viz[j] = 1;
                d[j] = d[nod] + k;
                q.push(j);

                if (j == y)
                {
                    fout << d[y];
                    break;
                }
            }
        }
    }

    fin.close();
    fout.close();

    return 0;
}
