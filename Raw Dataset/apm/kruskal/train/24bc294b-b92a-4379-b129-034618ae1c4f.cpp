#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>


using namespace std;



int N, M, t[200001], rang[2000001], cost_total;

vector <pair <int, int> > sol;



struct muchie{int x, y, cost; }L[400005];



bool cmp(muchie a, muchie b)

{

    return a.cost < b.cost;

}



int cauta(int nod)

{

    while (t[nod] != nod)

    {

        nod = t[nod];

    }

    return nod;

}



void unire(int a, int b)

{

    if (rang[a] < rang[b])

        t[a] = b;

    if (rang[a] > rang[b])

        t[b] = a;

    if (rang[a] == rang[b])

    {

        t[a] = b;

        rang[b]++;

    }

}



int main()

{

    ifstream fin("apm.in");

    ofstream fout("apm.out");



    fin >> N >> M;



    for(int i = 1; i <= M; i++)

        fin >> L[i].x >> L[i].y >> L[i].cost;



    for (int i = 1; i <= N; i++)

    {

        t[i] = i;

        rang[i] = 1;

    }



    sort(L+1, L+M+1, cmp);



    for (int i = 1; i <= M; i++)

    {

        int tx = cauta(L[i].x);

        int ty = cauta(L[i].y);



        if (tx != ty)

        {

            unire(tx, ty);

            sol.push_back({L[i].x, L[i].y});

            cost_total = cost_total + L[i].cost;

        }

    }



    fout << cost_total << "\n";

    fout << sol.size() << "\n";

    for (int i = 0; i < sol.size(); i++)

        fout << sol[i].first << " " << sol[i].second << "\n";

    return 0;

}
