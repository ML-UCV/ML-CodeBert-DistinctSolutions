#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <iomanip>
#include <cmath>
#include <algorithm>


using namespace std;

ifstream in("cmap.in");

ofstream out("cmap.out");
const long long inf = 1e18 + 5;

const int NMax = 1e5 + 5;



int N;



struct point {

    int x,y;

}v[NMax],aux[NMax];



bool cmp(point,point);

long long solve(int,int);

long long dist(point,point);



int main() {

    in>>N;

    for (int i=1;i <= N;++i) {

        in>>v[i].x>>v[i].y;

    }



    sort(v+1,v+N+1,cmp);







    long long mn = solve(1,N);

    out<<fixed<<setprecision(6)<<sqrt(mn)<<'\n';



    in.close();out.close();

    return 0;

}



long long solve(int st,int dr) {

    if (st >= dr) {

        return inf;

    }

    if (st == dr-1) {

        if (v[st].y > v[dr].y) {

            swap(v[st],v[dr]);

        }



        return dist(v[st],v[dr]);

    }



    long long mij = (st+dr)>>1,

        abscisa = v[mij].x,

        mn = min(solve(st,mij),solve(mij+1,dr));



    int nrAux = 0, i = st, j = mij+1;

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



    nrAux = 0;

    int root = sqrt(mn);

    for (i = st;i <= dr;++i) {

        if (abs(v[i].x - abscisa) <= mn) {

            aux[++nrAux] = v[i];

        }

    }



    for (i=1;i <= nrAux;++i) {

        for (int j=i+1;j <= i+7;++j) {

            mn = min(mn,dist(aux[i],aux[j]));

        }

    }



    return mn;

}



long long dist(point a,point b) {

    return 1LL * (a.x - b.x) * (a.x - b.x) + 1LL * (a.y - b.y) * (a.y - b.y);

}



bool cmp(point a,point b) {

    return a.x < b.x;

}
