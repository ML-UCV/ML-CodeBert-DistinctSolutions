#include <bits/stdc++.h>




using namespace std;



ifstream fin("apm.in");

ofstream fout("apm.out");



struct muchie {

    int x, y, c, OK;

}v[400001];



int t[200001];

int n, m, ct, nr;



int comp(muchie u,muchie v)

{

    return u.c<v.c;

}



int radacina(int x)

{

    int y,aux,r;





    r=x;

    while(t[r]!=0)

        r=t[r];





    y=x;

    while(t[y]!=0)

    {

        aux=t[y];

        t[y]=r;

        y=aux;

    }

    return r;



}

int main()

{

    int i,rx,ry,x,y;



    fin >> n >> m;

    for(i = 1; i <= m; i++)

        fin >> v[i].x >> v[i].y >> v[i].c;





    for(i=1; i <= n; i++)

        t[i] = 0;





   sort(v+1,v+m+1,comp);





    ct = 0; nr = 0; i = 1;

    while(nr < n-1)

    {

        x = v[i].x; y = v[i].y;

        rx=radacina(x);

        ry=radacina(y);



        if(rx != ry)

        {

            ct=ct+v[i].c;

            t[ry]=rx;

            v[i].OK = 1;

            nr++;

        }

        i++;

    }







    fout << ct << '\n'<<n-1<<'\n';

    for(i = 1; i <= m; i++)

        if(v[i].OK == 1)

            fout << v[i].x << ' ' << v[i].y << '\n';

}
