#include <bits/stdc++.h>




using namespace std;

ifstream fin("apm.in");

ofstream fout("apm.out");



struct graf{

    int plecare, destinatie, cost;

};

vector <graf> edges;

vector <graf> sols;

int t[200005], height[200005], n, m, cost_total, nr_muchii_adaugate;



bool compara(graf a, graf b)

{

    return (a.cost < b.cost);

}



int get_root(int k)

{

    while(t[k] != k)

        k = t[k];

    return k;

}



void unire(int a, int b)

{

    if(height[a] > height[b])

        t[b] = a;

    else if(height[b] > height[a])

        t[a] = b;

    else

        t[b] = a, height[a]++;

}



int main()

{

    int i, x, y;

    graf variabila;

    fin >> n >> m;

    for(i = 1; i <= n; i++)

        t[i] = i;

    for(i = 0; i < m; i++)

        fin >> variabila.plecare >> variabila.destinatie >> variabila.cost, edges.push_back(variabila);

    sort(edges.begin(), edges.end(), compara);

    for(i = 0; i < m; i++)

    {

        x = get_root(edges[i].plecare), y = get_root(edges[i].destinatie);

        if(x != y)

            cost_total+=edges[i].cost, unire(x, y), sols.push_back(edges[i]), nr_muchii_adaugate++;

    }

    fout << cost_total << '\n';

    fout << nr_muchii_adaugate << '\n';

    for(i = 0; i < nr_muchii_adaugate; i++)

        fout << sols[i].destinatie << ' ' << sols[i].plecare << '\n';



    return 0;

}
