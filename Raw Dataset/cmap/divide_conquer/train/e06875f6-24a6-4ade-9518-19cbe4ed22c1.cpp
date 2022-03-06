#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <iomanip>


using namespace std;

ifstream in("cmap.in");

ofstream out("cmap.out");





typedef long long ll;

const int NMax = 1e5 + 5;

const ll inf = 9e18 + 5;



int N;



struct elem {

    ll x,y;

}v[NMax],aux[NMax];



bool operator <(elem a,elem b) {

    return a.y < b.y;

}

bool cmp(elem a,elem b) {

    return a.x < b.x;

}



ll solve(int,int);

ll dist(elem,elem);



int main() {

    in>>N;

    for (int i=1;i<=N;++i) {

        in>>v[i].x>>v[i].y;

    }

    sort(v+1,v+N+1,cmp);



    ll dist = solve(1,N);

    out<<fixed<<setprecision(6)<<sqrt(dist)<<'\n';



    in.close();out.close();

    return 0;

}



ll solve(int st,int dr) {

    if (st == dr) {

        return inf;

    }

    if (dr - st + 1 == 2) {

        if (v[dr] < v[st]) {

            swap(v[st],v[dr]);

        }

        return dist(v[st],v[dr]);

    }



    ll mij = (st+dr)>>1,

        abscisa = v[mij].x,

        mn = min(solve(st,mij),solve(mij+1,dr)),

        nrAux = 0;



    int i = st, j = mij+1;

    while (i <= mij && j <= dr) {

        if (v[i] < v[j]) {

            aux[++nrAux] = v[i++];

        }

        else {

            aux[++nrAux] = v[j++];

        }

    }

    while (i <= mij) {

        aux[++nrAux] = v[i++];

    }

    while (j <= dr) {

        aux[++nrAux] = v[j++];

    }



    for (i=st;i<=dr;++i) {

        v[i] = aux[i - st + 1];

    }



    nrAux = 0;

    long double root = sqrt(mn);

    for (i=st;i<=dr;++i) {

        if (abs(v[i].x - abscisa) <= root) {

            aux[++nrAux] = v[i];

        }

    }



    for (i=1;i<=nrAux;++i) {

        for (j=i+1;j <= nrAux && j-i+1 <= 8;++j) {

            ll d = dist(aux[i],aux[j]);

            mn = min(mn,d);

        }

    }



    return mn;

}



ll dist(elem a,elem b) {

    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);

}
