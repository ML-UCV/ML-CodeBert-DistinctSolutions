#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <string.h>

#define NMAX 30010
#define MMAX 100030
#define INF 2147483647

using namespace std;

ifstream f("sate.in");
ofstream g("sate.out");

vector<pair<int, int>>     listaArce[NMAX];
int     n, m, x, y;
int     costuri[NMAX];
queue<int>  que;

void    bfs()
{
    que.push(x);

    costuri[x] = 0;

    while (!que.empty())
    {
        int aux = que.front();

        que.pop();

        for (int i = 0; i < listaArce[aux].size(); i++)
        {
            int nod = listaArce[aux][i].first;
            int cost = listaArce[aux][i].second;

            if (costuri[nod] == 0 && nod != x)
            {
                costuri[nod] = costuri[aux] + cost;
                que.push(nod);

                if (nod == y)
                    return;
            }
        }
    }
}

// https://www.infoarena.ro/problema/sate
//
int		main()
{
	f >> n >> m >> x >> y;

    for (int i = 0; i < m; i++)
	{
        int a, b, c;
        f >> a >> b >> c;
        listaArce[a].push_back(pair<int, int>(b, c));
        listaArce[b].push_back(pair<int, int>(a, -c));
    }

    bfs();
    
    g << costuri[y];

	return 0;
}