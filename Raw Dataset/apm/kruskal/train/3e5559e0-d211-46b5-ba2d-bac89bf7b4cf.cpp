#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
using namespace std;



ifstream f("apm.in");

ofstream g("apm.out");



struct muchie{

    int x,y,c;

};



int n,m,T[200005],rang[200005];

vector <muchie> v;

vector <muchie> l;



bool compare(muchie a, muchie b){

    return a.c < b.c;

}



void read(int &n, int &m, vector <muchie> &v){

    f>>n>>m;

    muchie var;

    for(int i=1; i<=m; i++){

        f>>var.x>>var.y>>var.c;

        v.push_back(var);

    }

    sort(v.begin(), v.end(), compare);

}



int Leader(int nod){



    if(T[nod] == nod)

        return nod;

    int x = Leader(T[nod]);

    T[nod] = x;

    return x;

}



void Unire(int x, int y){



    if(rang[x] > rang[y])

        T[y] = x;

    else{

        T[x] = y;

        if(rang[x] == rang[y])

            rang[y]++;

    }

}



void Kruskal(){

    int cost = 0, contor = 0;

    for(int i=0; i<m; i++){

        int rx = Leader(v[i].x);

        int ry = Leader(v[i].y);

        if(rx != ry)

        {

            l.push_back(v[i]);

            Unire(rx,ry);

            cost += v[i].c;

            contor++;

        }

    }

    g<<cost<<"\n"<<contor<<"\n";

    for(int i=0; i<contor; i++)

        g<<l[i].y<<" "<<l[i].x<<"\n";

}



int main(){

    read(n,m,v);

    for(int i=1; i<=n; i++)

        rang[i] = 1, T[i] = i;

    Kruskal();

}
