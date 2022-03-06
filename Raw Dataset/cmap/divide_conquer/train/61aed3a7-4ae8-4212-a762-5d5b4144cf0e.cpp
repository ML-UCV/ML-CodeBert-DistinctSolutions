#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>


using namespace std;

ifstream in("cmap.in");

ofstream out("cmap.out");



const int NMax = 1e5 + 5;

typedef long long ll;

const ll inf = 1e18 + 5;



int N;



struct elem {

    int x,y;

}v[NMax],aux[NMax];



bool cmp(elem,elem);

ll dist(elem,elem);

ll solve(int,int);



int main() {

    in>>N;

    for (int i=1;i<=N;++i) {

        in>>v[i].x>>v[i].y;

    }

    sort(v+1,v+N+1,cmp);



    out<<fixed<<setprecision(6)<<sqrt(solve(1,N));

    in.close();out.close();

    return 0;

}



ll solve(int st,int dr) {

    if (st == dr) {

        return inf;

    }

    else if (dr - st +1 == 2) {

        if (v[st].y > v[dr].y) {

            swap(v[st],v[dr]);

        }

        return dist(v[st],v[dr]);

    }



    ll mij = (st+dr)>>1,

        abscisa = v[mij].x,

        mn = min(solve(st,mij),solve(mij+1,dr));



    int i = st,

        j = mij+1,

        nrAux = 0;

    while (i <= mij && j <= dr) {

        if (v[i].y < v[j].y) {

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



    for (int i=st;i<=dr;++i) {

        v[i] = aux[i-st+1];

    }



    nrAux = 0;

    int root = sqrt(mn);

    for (int i=st;i<=dr;++i) {

        if (abs(v[i].x - abscisa) <= root) {

            aux[++nrAux] = v[i];

        }

    }



    for (int i=1;i<=nrAux;++i) {

        for (int j=i+1;j <= nrAux && j-i <= 7;++j) {

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
