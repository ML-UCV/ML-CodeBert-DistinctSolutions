#include <bits/stdc++.h>
using namespace std;
ifstream fin("cmap.in");

ofstream fout("cmap.out");



const int MAXN = 1e5 + 3;

const double EPS = 1e-8;

const long double INF = 1e12;



struct punct{

    long double x, y;

};

punct v[MAXN], b[MAXN], aux[MAXN];



long double minim = INF;



bool cmpx(punct a, punct b){

    return a.x + EPS < b.x or (a.x == b.x and a.y + EPS < b.y);

}

bool cmpy(punct a, punct b){

    return a.y + EPS < b.y or (a.y == b.y and a.x + EPS < b.x);

}



long double manhattan(punct a, punct b){

    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));

}



void interclasare(int st1, int dr1, int st2, int dr2){

    int indice = st1 - 1, i = st1, j = st2;



    while(i <= dr1 and j <= dr2){

        if(v[i].y < v[j].y)

            aux[++indice] = v[i++];

        else if(v[i].y > v[j].y)

            aux[++indice] = v[j++];

        else {

            if(v[i].x < v[i].y)

                aux[++indice] = v[i++];

            else

                aux[++indice] = v[j++];

        }

    }



    for(i; i <= dr1; ++i) aux[++indice] = v[i];

    for(j; j <= dr2; ++j) aux[++indice] = v[j];

    for(int k = st1; k <= dr2; ++k)

        v[k] = aux[k], aux[k] = {0, 0};

}



void dei(int st ,int dr){

    if(dr - st <= 2){

        for(int i = st; i < dr; ++i){

            for(int j = i + 1; j <= dr; ++j){

                minim = min(minim, manhattan(v[i], v[j]));

            }

        }

        sort(v + st, v + dr + 1, cmpy);

        return;

    }



    int m = (st + dr ) / 2, l = 0;

    punct mid = v[m];



    dei(st , m); dei(m + 1, dr);

    interclasare(st, m, m + 1, dr);



    for(int i = st; i <= dr; ++i){

        if(abs(mid.x - v[i].x) <= minim)

            b[++l] = v[i];

    }

    for(int i = 1; i <= l ;++i){

        for(int j = i + 1; j <= min(i + 8, l); ++j){

            minim = min(minim, manhattan(b[i], b[j]));

        }

    }



}



void afisare(int n){

    for(int i = 1; i <= n; ++i){

        fout << v[i].x << " " << v[i].y << '\n';

    }

    fout << minim << '\n';

}



int main(){

    int n; fin >> n;

    for(int i = 1; i <= n; ++i){

        fin >> v[i].x >> v[i].y;

    }

    sort(v + 1, v + n + 1, cmpx);



    dei(1, n);

    fout << setprecision(7) << fixed;

    fout << minim;

    return 0;

}
