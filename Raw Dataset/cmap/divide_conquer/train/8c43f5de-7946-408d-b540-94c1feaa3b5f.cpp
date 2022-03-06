#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <algorithm>


using namespace std;

ifstream in("cmap.in");

ofstream out("cmap.out");



const int NMax = 1e5 + 5;

typedef long long ll;

const ll inf = 3e18;



int N;

struct elem {

    int x,y;

}v[NMax],aux[NMax];

bool operator <(elem a,elem b) {

    if (a.y == b.y) {

        return a.x < b.x;

    }

    return a.y < b.y;

}



ll dist(elem,elem);

ll solve(int,int);

bool cmp(elem,elem);



int main()

{

    in>>N;

    for (int i=1;i<=N;++i) {

        in>>v[i].x>>v[i].y;

    }

    sort(v+1,v+N+1,cmp);



    out<<fixed<<setprecision(6)<<sqrt(solve(1,N))<<'\n';

    in.close();out.close();

    return 0;

}



ll solve(int st,int dr) {

    if (st == dr) {

        return inf;

    }

    if (dr-st+1 == 2) {

        if (!(v[st] < v[dr])) {

            swap(v[st],v[dr]);

        }



        return dist(v[st],v[dr]);

    }



    int mij = (st+dr)>>1,

        abscisa = v[mij].x;

    ll mn = min(solve(st,mij),solve(mij+1,dr));



    int nrAux = 0,i = st, j = mij+1;

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



    for (i=1;i<=nrAux;++i) {

        v[st+i-1] = aux[i];

    }



    nrAux = 0;

    double root = sqrt(mn);

    for (i=st;i<=dr;++i) {

        if (abs(v[i].x - abscisa) <= root) {

            aux[++nrAux] = v[i];

        }

    }



    for (i=1;i<=nrAux;++i) {

        for (int j=i+1;j<=nrAux && j-i+1 <= 8;++j) {

            mn = min(mn,dist(aux[i],aux[j]));

        }

    }



    return mn;

}



ll dist(elem a,elem b) {

    return 1LL * (a.x - b.x) * (a.x - b.x) + 1LL * (a.y - b.y) * (a.y - b.y);

}



bool cmp(elem a,elem b) {

    return a.x < b.x;

}
