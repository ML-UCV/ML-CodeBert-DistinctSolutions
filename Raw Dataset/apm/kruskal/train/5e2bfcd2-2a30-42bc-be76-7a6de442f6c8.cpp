#include <bits/stdc++.h>
using namespace std;



ifstream fin("apm.in");

ofstream fout("apm.out");



struct elem

{

    int dest, node, cost;

}v[400005];



int dads[200005];

int rnk[200005];



int cost, k;



int sol[200005][2];



 int n, m;





inline bool cmp(const elem &a, const elem &b)

{

    return a.cost < b.cost;

}



int root(int node)

{

    int father = dads[node];



    while(father != dads[father])

        father = dads[father];



    dads[node] = father;

    return father;

}



void join(int p, int q)

{

    p = root(p);

    q = root(q);



    if(rnk[p] < rnk[q])

        dads[p] = q;

    else

        if(rnk[p] > rnk[q])

            dads[q] = p;

    else

        rnk[q]++, dads[p] = q;

}



void kruskal()

{

    for(int i = 1; i <= m; i++)

        if(root(v[i].node) != root(v[i].dest))

            {

                join(v[i].node,v[i].dest);

                cost += v[i].cost;

                sol[++k][0] = v[i].node;

                sol[k][1] = v[i].dest;

            }

    fout << cost << '\n';

    fout << k << '\n';

    for(int i = 1; i <= k; i++)

        fout << sol[i][0] << " " << sol[i][1] << '\n';

}



int main()

{

    fin >> n >> m;



    for(int i = 1; i <= m; i ++)

    {

        int x, y, z;



        fin >> x >> y >> z;



        v[i] = {x,y,z};

    }



    for(int i = 1; i <= n; i++)

        dads[i] = i;



    sort(v + 1,v + m + 1,cmp);



    kruskal();

    return 0;

}
