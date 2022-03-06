#include <bits/stdc++.h>


using namespace std;



ifstream fin("apm.in");

ofstream fout("apm.out");



const int Nmax = 2e5 + 5;

const int Mmax = 4e5 + 5;



int n, m;

int t[Nmax];



pair <int, pair <int, int> > muchii[Mmax];

pair <int, int> sol[Mmax];



void Union(int x, int y)

{

    t[y] = x;

}



int Find(int x)

{

    int y, rad = x;



    while(t[rad])

        rad = t[rad];



    while(x != rad)

    {

        y = t[x];

        t[x] = rad;

        x = y;

    }



    return rad;

}



int main()

{

    fin >> n >> m;



    for(int i = 1; i <= m; i++)

        fin >> muchii[i].second.first >> muchii[i].second.second >> muchii[i].first;



    sort(muchii + 1, muchii + m + 1);

    int x, y, lg, cost;



    cost = lg = 0;

    for(int i = 1; i <= m; i++)

    {

        x = Find(muchii[i].second.first);

        y = Find(muchii[i].second.second);



        if(x != y)

        {

            cost += muchii[i].first;

            lg++;

            sol[lg] = muchii[i].second;



            Union(x, y);

        }

    }



    fout << cost << "\n" << lg << "\n";



    for(int i = 1; i <= lg; i++)

        fout << sol[i].first << " " << sol[i].second << "\n";



    fin.close();

    fout.close();

    return 0;

}
