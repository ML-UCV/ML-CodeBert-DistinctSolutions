#include <iostream>
#include<fstream>
#include<cmath>
#include<algorithm>
#include<climits>
#include<iomanip>
using namespace std;

ifstream f("cmap.in");

ofstream g("cmap.out");

struct punct

{

    long long a, b;

};

punct x[100001], y[100001], aux[100001];

bool crit(punct aa, punct bb)

{

    return ((aa.a < bb.a) || (aa.a == bb.a && aa.b < bb.b));

}

long long dist(punct aa, punct bb)

{

    return (aa.a - bb.a) * (aa.a - bb.a) + (aa.b - bb.b) * (aa.b - bb.b);

}

long long solutie(int st, int dr, punct *X, punct *Y)

{

    if(st >= dr - 1)

        return LLONG_MAX;

    if(dr - st == 2)

    {

        if(!crit(Y[st] , Y[st + 1]))

            swap(Y[st], Y[st + 1]);

        return dist(X[st], X[st + 1]);

    }

    int m = (dr + st) / 2;

    long long minim = min(solutie(st, m, X, Y), solutie(m, dr, X, Y));

    merge(Y + st, Y + m, Y + m, Y + dr, aux, crit);

    copy(aux, aux + (dr - st), Y + st);

    int it = 0;

    for(int i = st; i < dr; i++) if(abs(Y[i].b - X[m].a) <= minim)

            aux[it ++] = Y[i];

    for(int i = 0; i < it; i++)

    {

        for(int j = i + 1; j < it && j - i < 8; j++)

            minim = min(minim, dist(aux[i], aux[j]));

    }

    return minim;

}

int main()

{

    int n;

    f >> n;

    for(int i = 0; i < n; i++)

        f >> x[i].a >> x[i].b;

    sort(x, x + n, crit);

    for(int i = 0; i < n; i++)

    {

        y[i].a = x[i].b;

        y[i].b = x[i].a;

    }

    g << fixed << setprecision(6) << sqrt(solutie(0, n - 1, x, y));

    return 0;

}
