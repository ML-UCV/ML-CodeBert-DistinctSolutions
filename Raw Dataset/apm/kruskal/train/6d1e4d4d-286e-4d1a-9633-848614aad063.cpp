#include <stdio.h>
#include <algorithm>
using namespace std;



FILE *fin = fopen("apm.in", "r");

FILE *fout = fopen("apm.out", "w");



struct muchie {int x; int y; int cost; int ok;} muchii[400005];



int n,m,nr,costmin,i,daddy[200005],h[200005];



bool cmp(muchie a, muchie b)

{

    return a.cost < b.cost;

}



int bigDaddy(int x)

{

    int d;



    if(daddy[x] == x)

        return x;



    d = bigDaddy(daddy[x]);

    daddy[x] = d;

    return d;

}



void unire(int much)

{

    int x,y,d1,d2;



    x = muchii[much].x;

    y = muchii[much].y;



    d1 = bigDaddy(x);

    d2 = bigDaddy(y);



    if(d1 != d2)

    {

        muchii[much].ok = true;

        nr++;

        costmin += muchii[much].cost;



        if(h[d1] > h[d2])

            daddy[d2] = d1;

        else

        {

            daddy[d1] = d2;

            if(h[d1] == h[d2])

                h[d2]++;

        }

    }

}



int main()

{

    fscanf(fin, "%d%d", &n,&m);

    for(i=1; i<=m; ++i)

        fscanf(fin, "%d%d%d", &muchii[i].x,&muchii[i].y,&muchii[i].cost);



    for(i=1; i<=n; ++i)

        daddy[i] = i;



    stable_sort(muchii+1, muchii+m+1, cmp);



    nr = costmin = 0;



    for(i=1; i<=m; ++i)

        unire(i);



    fprintf(fout, "%d\n%d\n", costmin,nr);

    for(i=1; i<=m; ++i)

        if(muchii[i].ok)

            fprintf(fout, "%d %d\n", muchii[i].x,muchii[i].y);



    fclose(fin);

    fclose(fout);

    return 0;

}
