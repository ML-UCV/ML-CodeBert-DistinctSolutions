#include <fstream>
#include <vector>
#include <cmath>
using namespace std;

ifstream in("dmin.in");

ofstream out("dmin.out");

const int N = 1502, R = 104659, M = 1999999999;

const double ER = 0.000000001;

int poz[N], h[N], pos[N];

double d[N];

vector <pair<int,double>> v[N];

bool egal(double a, double b){

    return(abs(a - b) < ER);

}

bool comp(double a, double b){

    return((a - b) > ER);

}

void upHeap(int f){

    while(f/2 && comp(d[h[f/2]], d[h[f]])){

        swap(poz[h[f/2]], poz[h[f]]);

        swap(h[f/2], h[f]);

        f /= 2;

    }

}

void insertHeap(int val, int &l){

    h[++l] = val;

    poz[val] = l;

    upHeap(l);

}

void downHeap(int l){

    int f = 0, t = 1;

    while(t != f){

        f = t;

        if(f*2 <= l && comp(d[h[t]], d[h[f*2]]))

            t = f*2;

        if(f*2+1 <= l && comp(d[h[t]], d[h[f*2+1]]))

            t = f*2+1;

        swap(poz[h[t]],poz[h[f]]);

        swap(h[t],h[f]);

    }

}

int extractTop(int &l){

    int rad = h[1];

    poz[rad] = 0;

    swap(h[1],h[l--]);

    poz[h[1]] = 1;

    downHeap(l);

    return rad;

}

void dijkstra(int n){

    int l = 0, rad, sz, nod;

    double c;

    for(int i=2;i<=n;i++)

        d[i] = M;

    pos[1] = 1;

    insertHeap(1,l);

    while(l){

        rad = extractTop(l);

        sz = v[rad].size();

        for(int i=0;i<sz;i++){

            nod = v[rad][i].first;

            c = v[rad][i].second;

            if(egal(d[rad] + c, d[nod]))

                pos[nod] = (pos[nod] + pos[rad]) % R;

            if(comp(d[nod], d[rad] + c)){

                pos[nod] = pos[rad];

                d[nod] = d[rad] + c;

                if(poz[nod])

                    upHeap(poz[nod]);

                else

                    insertHeap(nod,l);

            }

        }

    }

}

int main()

{

    int n,m,x,y,z;

    in>>n>>m;

    for(int i=1;i<=m;i++){

        in>>x>>y>>z;

        v[x].push_back({y,log(z)});

        v[y].push_back({x,log(z)});

    }

    in.close();

    dijkstra(n);

    for(int i=2;i<=n;i++)

        out<<pos[i]<<" ";

    out<<"\n";

    out.close();

    return 0;

}
