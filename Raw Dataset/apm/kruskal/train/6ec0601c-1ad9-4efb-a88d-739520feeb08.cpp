#include <bits/stdc++.h>






using namespace std;



ifstream fin("apm.in");

ofstream fout("apm.out");



struct edge {

    int x, y, c, OK;

}v[400001];



int t[200001];

int N, M, ct, nr;

int rx,ry,x,y;



bool cmp(edge u,edge v){

    return u.c<v.c;

}



int radacina(int x) {



    int y,aux,r;

    r=x;



    while(t[r]!=0)

        r=t[r];



    y=x;



    while(t[y]!=0){

        aux=t[y];

        t[y]=r;

        y=aux;

    }

    return r;

}



int main()

{

    fin >> N >> M;

    for(int i = 1; i <= M; i++)

        fin >> v[i].x >> v[i].y >> v[i].c;



    for(int i=1; i <= N; i++)

        t[i] = 0;



   sort(v+1,v+M+1,cmp);



    ct = 0;

    nr = 0;

    int i = 1;



    while(nr < N-1) {

        x = v[i].x; y = v[i].y;

        rx=radacina(x);

        ry=radacina(y);

        if(rx != ry) {

            ct=ct+v[i].c;

            t[ry]=rx;

            v[i].OK = 1;

            nr++;

        }

        i++;

    }



    fout << ct << '\n'<<N-1<<'\n';



    for(int i = 1; i <= M; i++)

        if(v[i].OK == 1)

            fout << v[i].x << ' ' << v[i].y << '\n';



 return 0;

}
