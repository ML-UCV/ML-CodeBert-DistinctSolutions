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
double formula(punct a, punct b){
    return sqrt((((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y))));
}
punct v[MAXN];
punct aux[MAXN];
punct b[MAXN];
void interclasare(int st ,int mij ,int dr){
    int indice1 = st - 1, indice2 = mij , indice = st - 1;
    while(indice1 < mij and indice2 < dr){
        if(v[indice1 + 1].y < v[indice2 + 1].y) aux[++indice] = v[++indice1];
        else aux[++indice] = v[++indice2];
    }
    for(int i = indice1 + 1; i <= mij ; ++i)
        aux[++indice] = v[i];
    for(int i = indice2 + 1; i <= dr; ++i)
        aux[++indice] = v[i];
    for(int i = st; i <= dr; ++i)
        v[i] = aux[i];
}
void dei(int st, int dr){
    int m = (st + dr) / 2;
    if(dr - st <= 2){
        for(int i = st ; i <= dr - 1; ++i){
            for(int j = i + 1; j <= dr; ++j){
                minim = min(minim, formula(v[i], v[j]));
            }
        }
        sort(v + st, v + dr + 1, cmp2);
        return;
    }
    double middleX = v[m].x;
    dei(st, m); dei(m + 1, dr);
    interclasare(st, m, dr);
    int indice = 0;
    for(int i = st; i <= dr; ++i)
        if(abs(v[i].x - middleX) >= minim)
            b[++indice] = v[i];

    for(int i = 1; i <= indice - 8; ++i)
        for(int j = i + 1; j <= min(indice, i + 8) ; ++j)
            minim = min(minim, formula(b[i], b[j]));

}

int main(){
    ios::sync_with_stdio(false);
    fin.tie(0);fout.tie(0);
    int n ;
    fin >> n;
    for(int i = 1; i <= n ;++i)
        fin >> v[i].x >> v[i].y;
    sort(v + 1, v + n + 1, cmp);
    dei(1, n);
    fout << setprecision(7) << fixed << minim;
    return 0;
}
