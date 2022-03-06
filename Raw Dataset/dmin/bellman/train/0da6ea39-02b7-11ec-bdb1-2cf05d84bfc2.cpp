#include<stdio.h>
#include<math.h>
using namespace std;

const int N = 1505, M = 2505, INF = 100000, R = 104659;

int vf[2 * M], urm[2 * M], lst[N], h[N], poz[N], nrh, nrm, nrd[N];

double c[2 * M], v[N];

void adauga (int x, int y, double cost)

{

    vf[++nrm] = y;

    c[nrm] = cost;

    urm[nrm] = lst[x];

    lst[x] = nrm;

}

void schimba (int p1, int p2)

{

    int aux = h[p1];

    h[p1] = h[p2];

    h[p2] = aux;

    poz[h[p1]] = p1;

    poz[h[p2]] = p2;

}

void urca (int p)

{

    while (p > 1 && v[h[p]] < v[h[p>>1]])

    {

        schimba (p, p >> 1);

        p >>= 1;

    }

}

void coboara (int p)

{

    int bun = p, fs = 2 * p, fd = 2 * p + 1;

    if (fs <= nrh && v[h[fs]] < v[h[bun]])

        bun = fs;

    if (fd <= nrh && v[h[fd]] < v[h[bun]])

        bun = fd;

    if (bun != p)

    {

        schimba (bun, p);

        coboara (bun);

    }

}

double make_abs (double x)

{

    if (x < 0)

        return -x;

    return x;

}

int main ()

{

    FILE *in, *out;

    in = fopen ("dmin.in", "r");

    out = fopen ("dmin.out", "w");

    int n, m;

    fscanf (in, "%d%d", &n, &m);

    int i, x, y;

    double cost;

    for (i = 1; i <= m; i++)

    {

        fscanf (in, "%d%d%lf", &x, &y, &cost);

        cost = log(cost);

        adauga (x, y, cost);

        adauga (y, x, cost);

    }

    for (i = 1; i <= n; i++)

    {

        v[i] = INF;

        poz[i] = i;

        h[i] = i;

    }

    nrh = n;

    double eps = 0.00000001;

    v[1] = 0;

    nrd[1] = 1;

    int p;

    double aux;

    while (nrh > 0)

    {

        x = h[1];

        schimba (1, nrh--);

        coboara (1);

        p = lst[x];

        while (p != 0)

        {

            y = vf[p];

            cost = c[p];

            aux = cost + v[x];

            if (v[y] - aux > eps)

            {

                v[y] = cost + v[x];

                nrd[y] = nrd[x];

                urca (poz[y]);

            }

            else

                if (make_abs (aux - v[y]) <= eps)

                {

                    nrd[y] += nrd[x];

                    nrd[y] %= R;

                }

            p = urm[p];

        }

    }

    for (i = 2; i <= n; i++)

        fprintf (out, "%d ", nrd[i]);

    return 0;

}
