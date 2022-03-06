#include <iostream>
#include <fstream>
#include <algorithm>


using namespace std;



ifstream in("apm.in");

ofstream out("apm.out");



const int MMax = 400005;



pair <int, int> P[MMax];

int k;



int N, M, Total, TT[MMax], RG[MMax];



struct Muchie{

    int x, y, cost;

}V[MMax];



int Compare(Muchie a, Muchie b)

{

    return a.cost < b.cost;

}



void Citire()

{

    in >> N >> M;

    for(int i = 1; i <= M; ++ i)

        in >> V[i].x >> V[i].y >> V[i].cost;

    sort(V + 1, V + M + 1, Compare);

    for(int i = 1; i <= N; ++ i)

    {

        TT[i] = i;

        RG[i] = 1;

    }

}



int Find(int Nod)

{

    while(TT[Nod] != Nod)

        Nod = TT[Nod];

    return Nod;

}



void Unire(int x, int y)

{





    if(RG[x] < RG[y])

        TT[x] = y;

    if(RG[x] > RG[y])

        TT[y] = x;

    if(RG[x] == RG[y])

    {

        TT[x] = y;

        ++ RG[y];

    }

}



void Rezolva()

{

    for(int i = 1; i <= M; ++ i)

    {

        int tata_x = Find(V[i].x);

        int tata_y = Find(V[i].y);

        if(tata_x != tata_y)

        {

            Unire(tata_x, tata_y);

            P[++ k].first = V[i].x;

            P[k].second = V[i].y;

            Total += V[i].cost;

        }

    }

}



void Afisare()

{

    out << Total << '\n';

    out << N - 1 << '\n';

    for(int i = 1; i <= k; ++ i)

        out << P[i].second << " " << P[i].first << '\n';

}



int main()

{

    Citire();

    Rezolva();

    Afisare();

    return 0;

}
