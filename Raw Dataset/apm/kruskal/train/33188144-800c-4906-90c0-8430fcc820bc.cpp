#include <bits/stdc++.h>


using namespace std;



ifstream f ("apm.in");

ofstream g ("apm.out");



const int nmax = 2e5 + 1;



int rin[nmax];



struct Graf

{

    int x, y, cost;

};

Graf v[nmax], rasp[nmax];



bool Compara(Graf a, Graf b)

{

    return a.cost < b.cost;

}



int Serif(int i)

{

    if(rin[i] == i)

        return i;



    return rin[i] = Serif(rin[i]);

}



int main()

{

    int n, m, cnt = 0, k = 0;



    f >> n >> m;



    for(int i = 1; i <= m; ++i)

        f >> v[i].x >> v[i].y >> v[i].cost;



    for(int i = 1; i <= n; ++i)

        rin[i]=i;



    sort(v + 1, v + m + 1, Compara);



    for(int i = 1; i <= m; ++i)

    {

        if(Serif(v[i].x) != Serif(v[i].y))

        {

            rin[Serif(v[i].y)] = v[i].x;

            cnt += v[i].cost;

            rasp[++k].x = v[i].x;

            rasp[k].y = v[i].y;

        }

    }



    g<<cnt<<'\n';

    g<<k<<'\n';



    for(int i = 1; i <= k; ++i)

        g<<rasp[i].x<<" "<<rasp[i].y<<'\n';

    return 0;

}
