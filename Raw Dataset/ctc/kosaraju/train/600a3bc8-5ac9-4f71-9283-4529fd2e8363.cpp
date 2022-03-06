#include <bits/stdc++.h>


using namespace std;



ifstream fin("ctc.in");

ofstream fout("ctc.out");



const int Nmax = 1e5 + 5;



int n, m, lg, nrc;

int sortTop[Nmax];

bitset <Nmax> viz;

vector <int> L[Nmax], G[Nmax], sol[Nmax];



void SortTop(int nod)

{

    viz[nod] = 1;

    for(auto i : L[nod])

        if(!viz[i]) SortTop(i);



    sortTop[++lg] = nod;

}



void Componente(int nod)

{

    viz[nod] = 1;

    for(auto i : G[nod])

        if(!viz[i]) Componente(i);



    sol[nrc].push_back(nod);

}



int main()

{

    fin >> n >> m;



    int x, y;

    for(int i = 1; i <= m; i++)

    {

        fin >> x >> y;

        L[x].push_back(y);

        G[y].push_back(x);

    }



    for(int i = 1; i <= n; i++)

        if(!viz[i]) SortTop(i);



    for(int i = 1; i <= n ; i++)

        cout << sortTop[i] << " ";



    viz.reset();

    for(int i = n; i >= 1; i--)

        if(!viz[sortTop[i]])

        {

            nrc++;

            Componente(sortTop[i]);

        }



    fout << nrc << "\n";



    for(int i = 1; i <= nrc; fout << "\n", i++)

        for(auto j : sol[i])

            fout << j << " ";



    fin.close();

    fout.close();

    return 0;

}
