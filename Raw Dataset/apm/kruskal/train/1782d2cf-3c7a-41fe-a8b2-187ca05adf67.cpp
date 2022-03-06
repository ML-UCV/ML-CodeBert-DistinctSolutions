#include <stdio.h>
#include <stdlib.h>


typedef struct _edge {

    int source, dest, cost;

}edge;



int Find(int x, int *c) {

    int y = x, t;

    while(y != c[y])

        y = c[y];



    while(x != y) {

        t = c[x];

        c[x] = y;

        x = t;

    }



    return x;

}



void Unite(int x, int y, int *c) {

    x = Find(x, c);

    y = Find(y, c);

    c[y] = x;

}



int cmp_edges(const void *pa, const void *pb) {

    edge a = *(edge *)pa;

    edge b = *(edge *)pb;



    return a.cost-b.cost;

}



int APM_Kruskal(int n, int *c, int m, edge *e, edge *out) {

    int cost = 0, sz = 0;



    for(int i = 0; i < m; i++) {

        int x = e[i].source, y = e[i].dest, z = e[i].cost;

        if(Find(x, c) != Find(y, c)) {

            Unite(x, y, c);

            cost+=z;

            out[sz++] = e[i];

        }

    }



    return cost;

}



int main() {



    FILE *input = fopen("apm.in", "r");

    FILE *output = fopen("apm.out", "w");

    int n, m, *c;

    edge *e, *out;



    fscanf(input, "%d%d", &n, &m);



    c = (int *) calloc(n + 1, sizeof(int));

    e = (edge *) calloc(m, sizeof(edge));

    out = (edge *) calloc(n - 1, sizeof(edge));



    for(int i = 1; i <= n; i++)

        c[i] = i;



    for(int i = 0; i < m; i++)

        fscanf(input, "%d %d %d", &e[i].source, &e[i].dest, &e[i].cost);



    qsort(e, m, sizeof(edge), cmp_edges);



    int apm_cost = APM_Kruskal(n, c, m, e, out);

    fprintf(output, "%d\n", apm_cost);



    fprintf(output, "%d\n", n - 1);



    for(int i = 0; i < n - 1; i++) {

        fprintf(output, "%d %d\n", out[i].source, out[i].dest);

    }



    free(c);

    free(e);

    free(out);



    fclose(input);

    fclose(output);



    return 0;

}
