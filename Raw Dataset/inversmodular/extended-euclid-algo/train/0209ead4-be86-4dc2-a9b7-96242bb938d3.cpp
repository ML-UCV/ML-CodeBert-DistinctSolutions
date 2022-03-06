#include <cstdio>


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

    int t, a, b, c, x, y;

    fscanf(f, "%d%d", &a,&b);

    eulcid_eXt(a, b, 1, x, y);

    if(x<0) x=(b+x%b)%b;

    fprintf(g, "%d", x);

    return 0;

}
