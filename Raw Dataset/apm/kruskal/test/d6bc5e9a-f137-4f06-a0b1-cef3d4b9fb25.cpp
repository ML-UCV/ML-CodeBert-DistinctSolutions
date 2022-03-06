#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("apm.in");

ofstream fout("apm.out");



struct muchie

{

    int x, y, cost;

};



int pivot(int p, int q, muchie v[])

{

    muchie x = v[p];

    while(p<q)

    {

        while(p<q && v[q].cost >= x.cost)q--;

        v[p]=v[q];

        while(p<q && v[p].cost <= x.cost)p++;

        v[q]=v[p];

    }

    v[p] = x;

    return p;

}



void QS(int p, int q, muchie v[])

{

    if(p < q)

    {

        int a = pivot(p, q, v);

        QS(p, a-1, v);

        QS(a+1, q, v);

    }

}



int radacina(int x, int t[])

{

    while(t[x])x=t[x];

    return x;

}



int main()

{

    int n, m, k, p, q, c, rp, rq, s;

    fin>> n>> m;

    int t[n+1], h[n+1];

    muchie v[m+1], w[n];

    for(int i = 1; i <= n; ++i)t[i]=h[i]=0;

    for(int i = 1; i <= m; ++i)

    {

        fin>> v[i].x >> v[i].y >> v[i].cost;

    }



    QS(1, m, v);
    k=0;

    s=0;

    for(int i = 1; i<=m && k < n-1 ; ++i)

    {

        p = v[i].x;

        q = v[i].y;

        c = v[i].cost;

        rp = radacina(p, t);

        rq = radacina(q, t);

        if( rp != rq )

        {

            s+=v[i].cost;

            w[++k] = v[i];

            if(h[rp] > h[rq]) t[rq] = rp;

            else

            {

                t[rp] = rq;

                if(h[rp] == h[rq]) h[rq] ++;

            }

        }

    }



    fout << s<<'\n'<<k<<'\n';

    for(int i=1; i<=k; ++i)

    {

        fout<<w[i].x <<' '<<w[i].y <<'\n';

    }

    return 0;

}
