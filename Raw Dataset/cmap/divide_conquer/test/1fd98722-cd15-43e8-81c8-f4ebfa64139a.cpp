#include <bits/stdc++.h>
using namespace std;

ifstream fin("cmap.in");
ofstream fout("cmap.out");

const int MAXN = 1e5 + 1;
const double INF = 1e12;
const double EPS = 1e-8;
double minim = INF;
struct punct{
    double x, y;
};
bool cmp(punct a, punct b){
    return a.x + EPS < b.x or (abs(a.x - b.x) <= EPS and a.y + EPS < b.y);
}
bool cmp2(punct a, punct b){
    return a.y + EPS < b.y or (abs(a.y - b.y) <= EPS and a.x + EPS < b.x);
}
double form(punct a, punct b){
    return sqrt((((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y))));
}

punct v[MAXN];
punct b[MAXN];

void di(int st, int dr){
    int m = (st + dr) / 2;
    if(dr - st <= 2){
        for(int i = st ; i <= dr - 1; ++i){
            for(int j = i + 1; j <= dr; ++j){
                minim = min(minim, form(v[i], v[j]));
            }
        }
        return;
    }
    double middleX = v[m].x;
    di(st, m); di(m + 1, dr);
    int indice = 0;
    for(int i = st; i <= dr; ++i)
        if(abs(v[i].x - middleX) <= minim)
            b[++indice] = v[i];
    sort(b + 1, b + indice + 1, cmp2);
    for(int i = 1; i <= indice; ++i)
        for(int j = i + 1; j <= min(indice, i + 8) ; ++j)
            minim = min(minim, form(b[i], b[j]));
}

int main(){

    int n ;
    fin >> n;
    for(int i = 1; i <= n ;++i)
        fin >> v[i].x >> v[i].y;
    sort(v + 1, v + n + 1, cmp);
    di(1, n);
    fout << setprecision(6) << fixed << minim;

    return 0;
}
