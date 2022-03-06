#include <fstream>
#include <vector>
#include <queue>
#define mp make_pair

using namespace std;

ifstream in("sate.in");
ofstream out("sate.out");

const int Nmax = 30005;

queue<int> Q;
vector<pair<int, int> > A[Nmax];

void BFS (int x, int&n, vector<int>&d)
{
    for (int i = 1; i <= n; i++)
        d[i] = -1;
    d[x] = 0;

    Q.push(x);

    while (!Q.empty())
    {
        int k = Q.front();
        Q.pop();

        for (auto i = 0; i < A[k].size(); i++)
        {
            int nod = A[k][i].first;
            int cost = A[k][i].second;

            if (d[nod] == -1)
            {
                if (nod > k)
                    d[nod] = d[k] + cost;
                else
                    d[nod] = d[k] - cost;
                Q.push(nod);
            }
        }
    }
}

int main()
{
    int n, m, start, finish;
    vector<int> d(Nmax);

    in >> n >> m >> start >> finish;

    for (int i = 1; i <= m; i++)
    {
        int x, y, c;
        in >> x >> y >> c;

        A[x].push_back(mp(y, c));
        A[y].push_back(mp(x, c));
    }

    BFS(start, n, d);

    out << d[finish];
    return 0;
}
