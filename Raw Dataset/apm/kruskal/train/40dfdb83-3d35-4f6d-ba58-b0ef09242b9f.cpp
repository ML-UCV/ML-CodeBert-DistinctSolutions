#include <bits/stdc++.h>




using namespace std;



ifstream fin ("apm.in");

ofstream fout ("apm.out");



pair < int , int > P[400005];

int n, m, total, TT[400005], k;



struct Edge {

    int x, y, c;

}V[400005];



bool fcmp (Edge a, Edge b) {

    return a.c < b.c;

}



void Read () {

    fin >> n >> m;

    for (int i = 1; i <= m; ++i) fin >> V[i].x >> V[i].y >> V[i].c;

    sort (V + 1, V + m + 1, fcmp);

}



int Find (int i) {

    if (TT[i] == i)

        return i;

    return TT[i] = Find(TT[i]);

}



void Unite (int i, int j) {

    int ti, tj;

    ti = Find(i);

    tj = Find(j);

    TT[tj] = ti;

}



void Solve () {

    for (int i = 1; i <= m; ++i)

        TT[i] = i;

    for (int i = 1; i <= m; ++i) {

        int xx = Find (V[i].x), yy = Find (V[i].y);

        if (xx != yy) {

            Unite (xx, yy);

            P[++k] = {V[i].x, V[i].y};

            total += V[i].c;

        }

    }

}



void Print () {

    fout << total << '\n' << n - 1 << '\n';

    for (int i = 1; i <= k; ++i) fout << P[i].first << ' ' << P[i].second << ' ' << '\n';

}



int main() {

    Read ();

    Solve ();

    Print ();

    return 0;

}
