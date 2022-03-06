#include    <fstream>
#include    <iostream>
#include    <algorithm>
using namespace std;

ifstream fin("apm.in");

ofstream fout("apm.out");

const int NMax = 400005;

pair <int, int> P[NMax];

int N, M, Total, TT[NMax], k, RG[NMax];

struct Edge

{

    int x, y, c;



}V[NMax];

bool Compare(Edge a, Edge b)

{

    return a.c < b.c;

}

void Read()

{

    fin >> N >> M;

    for (int i = 1; i <= M; i++)

        fin >> V[i].x >> V[i].y >> V[i].c;

    sort(V + 1, V + M + 1, Compare);

    for (int i = 1; i <= M; i++)

        cout << V[i].x << " " << V[i].y << " " << V[i].c << "\n";

}

int Find(int nod)

{

    while (TT[nod] != nod)

        nod = TT[nod];

    return nod;

}

void Unite(int x, int y)

{

    if (RG[x] < RG[y])

        TT[x] = y;

    if (RG[y] < RG[x])

        TT[y] = x;

    if (RG[x] == RG[y])

    {

        TT[x] = y;

        RG[y]++;

    }

}

void Solve()

{

    for (int i = 1; i <= M; i++)

    {



        if (Find(V[i].x) != Find(V[i].y))

        {



            Unite(Find(V[i].x), Find(V[i].y));

            P[++k].first = V[i].x;

            P[k].second = V[i].y;

            Total += V[i].c;

        }

    }

}

int main()

{

    Read();

    for (int i = 1; i <= M; i++)

    {

        TT[i] = i;

        RG[i] = 1;

    }

    Solve();

    fout << Total << "\n";

    fout << N - 1 << "\n";

    for (int i = 1; i <= k; i++)

        fout << P[i].first << " " << P[i].second << "\n";

    return 0;

}
