#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>




using namespace std;



ifstream in("apm.in");

ofstream out("apm.out");



struct muchie

{

    int x, y;

    short c;

}m[400005];



int N, M, cost, ct;

int tata[200005], id[200005];



bool comp(muchie a, muchie b)

{

    return a.c < b.c;

}



void citire()

{

    in >> N >> M;

    for(int i = 1; i <= M; i++)

        in >> m[i].x >> m[i].y >> m[i].c;



    sort(m + 1, m + M + 1, comp);

}



int gasire(int x)

{

    if(tata[x] != x)

        tata[x] = gasire(tata[x]);

    return tata[x];

}



void unire(int a, int b)

{

    if(a != b)

        if(a < b)

            tata[b] = a;

        else

            tata[a] = b;

}



void kruskal()

{

    for(int i = 1; i <= M; i++)

    {

        int a = gasire(m[i].x);

        int b = gasire(m[i].y);

        if(a != b)

        {

            unire(a, b);

            cost += m[i].c;

            id[++ct] = i;

        }

    }

}



int main()

{

    citire();

    for(int i = 1; i <= N; i++)

        tata[i] = i;



    kruskal();



    out << cost << '\n' << ct << '\n';

    for(int i = 1; i <= N - 1; i++)

        out << m[id[i]].x << ' ' << m[id[i]].y << '\n';

}
