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

double dist(elem,elem);

double solve(int,int);



int main()

{

    in>>N;

    for (int i=1;i<=N;++i) {

        in>>v[i].x>>v[i].y;

    }



    sort(v+1,v+N+1,cmp1);





    double mn = solve(1,N);

    out<<fixed<<setprecision(6)<<mn<<'\n';



    return 0;

}



double solve(int st,int dr) {

    if (dr-st+1 == 1) {

        return inf;

    }

    if (dr-st+1 == 2) {

        if (!(v[st] < v[dr])) {

            swap(v[st],v[dr]);

        }



        return dist(v[st],v[dr]);

    }



    int debug = 0;



    if (debug) {

        cout<<st<<' '<<dr<<'\n';

        for (int i=st;i<=dr;++i) {

            cout<<v[i].x<<' '<<v[i].y<<'\n';

        }

        cout<<'\n';

    }





    int mij = (st+dr)>>1;

    int abscisa = v[mij].x;

    double mn = min(solve(st,mij),solve(mij+1,dr));





    if (debug) {

        cout<<mn<<'\n';

        for (int i=st;i<=dr;++i) {

            cout<<v[i].x<<' '<<v[i].y<<'\n';

        }

        cout<<'\n';

    }





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

        if (debug)

        cout<<aux[i].x<<' '<<aux[i].y<<'\n';

    }

    if (debug)

    cout<<"\n";



    nrAux = 0;

    for (i=st;i<=dr;++i) {

        if (abs(v[i].x-abscisa) <= mn) {

            aux[++nrAux] = v[i];

        }

    }



    for (i=1;i<=nrAux;++i) {

        if (debug)

        cout<<aux[i].x<<' '<<aux[i].y<<'\n';

        for (j=i+1;j <= nrAux && j-i+1 <= 8;++j) {

            double d = dist(aux[i],aux[j]);

            if (debug) {

                cout<<i<<' '<<j<<' '<<d<<'\n';

            }

            mn = min(mn,d);

        }

    }

    if (debug)

    cout<<"\n\n";

    return mn;

}



bool cmp1(elem a,elem b) {
    return a.x < b.x;

}



double dist(elem a,elem b) {

    double val = sqrt(1LL * (a.x - b.x) * (a.x - b.x) + 1LL * (a.y - b.y) * (a.y - b.y));

    return val;

}
