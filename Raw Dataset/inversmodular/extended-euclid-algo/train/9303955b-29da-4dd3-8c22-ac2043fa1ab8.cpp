#include <iostream>
#include <cstdio>
using namespace std;



int t, a, n, c, x, y;



void eulcid_eXt(int a, int b, int c, int &x, int &y)

{

    int q[100], x0, y0, r, p=0;

    while(b != 0)

    {

        r = a%b;

        q[++p] = a/b;

        a=b;

        b=r;



    }

    if(c%a) {x=y=0;return;}

    x=x0 = c/a;

    y=y0 = 0;

    while(p)

    {

        x= y0;

        y = x0 - (q[p--]*y0);

        x0 = x;

        y0 = y;

    }

}



int main()

{

    FILE *f = fopen("inversmodular.in", "r");

    FILE *g = fopen("inversmodular.out", "w");

    fscanf(f, "%d%d", &a,&n);

    eulcid_eXt(a, n, 1, x, y);

    x=((long long)n+x%n)%n;

    fprintf(g, "%d", x);

    return 0;

}
