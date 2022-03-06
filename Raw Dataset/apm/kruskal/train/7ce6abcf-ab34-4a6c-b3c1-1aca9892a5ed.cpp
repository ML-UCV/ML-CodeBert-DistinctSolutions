#include <bits/stdc++.h>


using namespace std;



int father[200005];

int depth[200005];



FILE *in = fopen("apm.in", "r"), *out = fopen("apm.out", "w");



int get_father(int x)

{

    if(x != father[x])

        father[x] = get_father(father[x]);

    return father[x];

}



int nr_unions;



struct pereche

{

    int x, y;

} pairs[200005];

int pr_size = 0;



int total_cost;



void unite(int x, int y, int c)

{

    int cpy_x = x, cpy_y = y;

    x = get_father(x);

    y = get_father(y);

    if(x != y)

    {

        total_cost += c;

        pairs[pr_size].x = cpy_x;

        pairs[pr_size].y = cpy_y;

        pr_size++;



        nr_unions--;

        if(depth[y] > depth[x]) swap(x, y);



        father[y] = x;

        depth[x]++;

    }

}



struct edge

{

    int x, y, c;

} edges[400005];



bool cmp(const edge &a, const edge &b)

{

    return a.c < b.c;

}



int main()

{

    int n, m;

    fscanf(in, "%d%d", &n, &m);



    for(int i = 0; i < m; i++)

    {

        fscanf(in, "%d%d%d", &edges[i].x, &edges[i].y, &edges[i].c);

    }



    for(int i = 0; i <= n; i++)

    {

        father[i] = i;

        depth[i] = 1;

    }



    sort(edges, edges + m, cmp);



    nr_unions = n - 1;

    for(int i = 0; i < m && nr_unions > 0; i++)

    {

        unite(edges[i].x, edges[i].y, edges[i].c);

    }



    fprintf(out, "%d\n", total_cost);

    fprintf(out, "%d\n", pr_size);



    for(int i = 0; i < pr_size; i++)

    {

        fprintf(out, "%d %d\n", pairs[i].x, pairs[i].y);

    }

}
