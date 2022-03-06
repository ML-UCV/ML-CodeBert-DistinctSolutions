#include <fstream>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <cstring>
using namespace std;



const int Nmax = 100005;

int N;



struct Point

{

    int x, y;

} P[Nmax], V[Nmax];



long long minD = 4e18;



bool smallerX(const Point& p1, const Point& p2) { return (p1.x < p2.x); }

bool smallerY(const Point& p1, const Point& p2) { return (p1.y < p2.y); }



long long dist(const Point& p1, const Point& p2)

{

    int dx = p2.x - p1.x,

        dy = p2.y - p1.y;

    return (1LL * dx * dx) + (1LL * dy * dy);

}





void read()

{

    ifstream fin("cmap.in");

    fin >> N;

    for(int i = 0; i < N; i++)

        fin >> P[i].x >> P[i].y;

    fin.close();

}



void print_sol()

{

    ofstream fout("cmap.out");

    fout << fixed << setprecision(6) << sqrt(minD) << '\n';

    fout.close();

}



void find_closest(int L, int R)

{

    if(R - L == 1)

    {

        if(P[L].y > P[L + 1].y) swap(P[L], P[L + 1]);

        minD = min(minD, dist(P[L], P[L+1]));

        return;

    }



    int M = (L + R)/2;

    int sepx = P[M].x;



    find_closest(L, M);

    find_closest(M, R);



    merge(P+L, P+M, P+M, P+R + 1, V, smallerY);

    memcpy(P+L, V, (R-L + 1) * sizeof(Point));

    int k = 0;

    for(int i = L; i <= R; i++)

        if(abs(P[i].x - sepx) <= minD)

            V[k++] = P[i];



    for(int i = 0; i < (k - 1); i++)

        for(int j = (i + 1); j < min(k, i + 8); j++)

            minD = min(minD, dist(V[i], V[j]));



}



int main()

{

    read();

    sort(P, P+N, smallerX);

    find_closest(0, N-1);

    print_sol();

    return 0;

}
