#include <iostream>
#include <fstream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <iomanip>


using namespace std;

ifstream in("cmap.in");

ofstream out("cmap.out");







const int NMax = 1e5 + 5;

const long long inf = 1e18 + 5;



int N;



struct elem {

    int x,y;

    elem(int _x = 0,int _y = 0) {

        x = _x;

        y = _y;

    }

}v[NMax],aux[NMax];



bool operator <(elem a,elem b) {

    return a.y < b.y;

}



bool cmp(elem a,elem b) {

    return a.x < b.x;

}



long long solve(int,int);

long long dist(elem,elem);



int main() {

    in>>N;

    for (int i=1;i <= N;++i) {

        int x,y;

        in>>x>>y;

        v[i] = elem(x,y);

    }



    sort(v +1,v +N+1,cmp);



    out<<fixed<<setprecision(6)<<sqrt(solve(1,N))<<'\n';



    in.close();out.close();

    return 0;

}



long long solve(int st,int dr) {

    if (st == dr) {

        return inf;

    }

    else if (dr - st + 1 == 2) {

        if (v[dr] < v[st]) {

            swap(v[st],v[dr]);

        }



        return dist(v[st],v[dr]);

    }



    int mij = (st+dr)/2,

        abscisa = v[mij].x,

        nrAux = (dr-st+1);

    long long mn = min(solve(st,mij),solve(mij+1,dr));



    merge(v+st,

          v+mij+1,

          v+mij+1,

          v+dr+1,

          aux+1);



    nrAux = 0;

    for (int i=st;i <= dr;++i) {

        v[i] = aux[++nrAux];

    }



    nrAux = 0;

    double root = sqrt(mn);

    for (int i=st;i <= dr;++i) {

        if (abs(v[i].x - abscisa) <= root) {

            aux[++nrAux] = v[i];

        }

    }



    for (int i=1;i <= nrAux;++i) {

        for (int j=i+1;j <= nrAux && j-i+1 <= 8;++j) {

            mn = min(mn,dist(aux[i],aux[j]));

        }

    }



    return mn;

}



long long dist(elem a,elem b) {

    return 1LL*(a.x - b.x) * (a.x - b.x) + 1LL*(a.y - b.y) * (a.y - b.y);

}
