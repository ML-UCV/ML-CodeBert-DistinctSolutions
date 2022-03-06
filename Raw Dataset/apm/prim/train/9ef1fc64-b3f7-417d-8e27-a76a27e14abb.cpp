#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <set>
#include <assert.h>
#include <limits.h>
using namespace std;



const int N = 200005;



ifstream fin("apm.in");

ofstream fout("apm.out");



vector<pair<int, int>> g[N];

bool vis[N];

int tata[N], minCost[N];

int n, m;





int main()

{

    fin >> n >> m;

    for (int i = 0; i < m; i++)

    {

        int x, y, c;

        fin >> x >> y >> c;

        g[x].push_back({ y, c });

        g[y].push_back({ x, c });

    }



    set<pair<int, int>> heap;

    heap.insert({ 0, 1 });

    for (int i = 2; i <= n; i++)

        minCost[i] = INT_MAX;



    int costTotal = 0;

    while (!heap.empty())

    {

        pair<int, int> minim = *heap.begin();

        int nod = minim.second;

        int cost = minim.first;

        heap.erase(heap.begin());



        if (vis[nod])

            continue;



        vis[nod] = true;

        costTotal += cost;



        for (auto y : g[nod])

            if (!vis[y.first] && y.second < minCost[y.first])

            {

                if (vis[y.first] && y.second < minCost[y.first])

                    heap.erase(heap.find({ minCost[y.first], y.first }));



                heap.insert({ y.second, y.first });

                minCost[y.first] = y.second;

                tata[y.first] = nod;

            }

    }



    fout << costTotal << '\n';

    fout << n - 1 << '\n';

    for (int i = 2; i <= n; i++)

        fout << i << ' ' << tata[i] << '\n';



    return 0;

}
