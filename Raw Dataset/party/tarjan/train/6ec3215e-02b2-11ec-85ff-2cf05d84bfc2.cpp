#include <iostream>
#include <fstream>
#include <algorithm>
#include <queue>
#include <vector>






using namespace std;



ifstream fin("party.in");

ofstream fout("party.out");



const int Nmax = 250;



int N, M;

queue <int> Q, Initialize;

vector <int> G[Nmax], sol;

vector <bool> viz(Nmax), val(Nmax);



inline int Not(int x)

{

    return (x <= N ? N + x : x - N);

}



bool DFS(int nod)

{

    Q.push(nod);

    for(unsigned i = 0; i < G[nod].size(); i++)

        if(viz[G[nod][i]])

            if(!val[G[nod][i]])

                return 0;

            else;

        else

        {

            viz[G[nod][i]] = viz[Not(G[nod][i])] = 1;

            val[G[nod][i]] = 1; val[Not(G[nod][i])] = 0;

            if(!DFS(Not(G[nod][i])))

                return 0;

        }

    return 1;

}



void Clear()

{

    while(!Q.empty())

    {

        int nod = Q.front(); Q.pop();

        viz[nod] = viz[Not(nod)] = 0;

    }

}



bool Right(int nod, bool v)

{

    viz[nod] = viz[Not(nod)] = 1;

    val[nod] = v; val[Not(nod)] = !v;

    if(v == 0)

        return DFS(nod);

    else

        return DFS(Not(nod));

}



int main()

{

    fin >> N >> M;

    for(int i = 1; i <= M; i++)

    {

        int x, y, tip;

        fin >> x >> y >> tip;



        if(!tip);

        else if(tip == 1)

            y = Not(y);

        else if(tip == 2)

            x = Not(x);

        else

            x = Not(x), y = Not(y);



        G[x].push_back(y);

        G[y].push_back(x);

    }



    for(int i = 1; i <= N; i++)

        if(!viz[i])

            if(!Right(i, 1))

            {

                Clear();

                if(!Right(i, 0))

                {

                    fout << "0";

                    return 0;

                }

                Q = Initialize;

            }

    int nr = 0;

    for(int i = 1; i <= N; i++)

        if(val[i])

        {

            nr++;

            sol.push_back(i);

        }

    fout << nr << '\n';

    for(int i = 0; i < nr; i++)

        fout<< sol[i] << '\n';

    return 0;

}
