#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>


using namespace std;

ifstream in("cmap.in");

ofstream out("cmap.out");



const int NMax = 1e5 + 5;

typedef long long ll;

const ll inf = 1e18;



int N;



struct elem {

    int x,y;

}v[NMax],aux[NMax];



bool operator <(elem a,elem b) {

    return a.y < b.y;

}



bool cmp1(elem,elem);

ll dist(elem,elem);

ll solve(int,int);
int main()

{

    in>>N;

    for (int i=1;i<=N;++i) {

        in>>v[i].x>>v[i].y;

    }

    sort(v+1,v+N+1,cmp1);



    double mn = sqrt(solve(1,N));

    out<<fixed<<setprecision(6)<<mn<<'\n';



    return 0;

}



ll solve(int st,int dr) {

    if (dr-st+1 == 1) {

        return inf;

    }

    if (dr-st+1 == 2) {

        if (!(v[st] < v[dr])) {

            swap(v[st],v[dr]);

        }



        return dist(v[st],v[dr]);

    }



    int mij = (st+dr)>>1;

    int abscisa = v[mij].x;

    ll mn = min(solve(st,mij),solve(mij+1,dr));







    int nrAux = 0;

    int i = st,j = mij + 1;

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

    for (i=st;i<=dr;++i) {

        if (abs(v[i].x-abscisa) <= mn) {

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



bool cmp1(elem a,elem b) {

    return a.x < b.x;

}



ll dist(elem a,elem b) {

    ll val = 1LL * (a.x - b.x) * (a.x - b.x) + 1LL * (a.y - b.y) * (a.y - b.y);

    return val;

}
