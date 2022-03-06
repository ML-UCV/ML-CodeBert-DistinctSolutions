#include <bits/stdc++.h>
using namespace std;



ifstream fin("inv.in");

ofstream fout("inv.out");

const int MAXN = 1e5 + 4;

const int MOD = 9917;

int rasp, v[MAXN], x[MAXN];

void interclasare(int st1 , int dr1, int st2, int dr2){

    int i = st1 , j = st2, indice = st1 - 1;

    while(i <= dr1 and j <= dr2){

        if(v[i] <= v[j]){

            x[++indice] = v[i++];

        }

        else{

            x[++indice] = v[j++];

            rasp += (dr1 - i + 1);

            rasp %= MOD;

        }

    }

    for(i; i <= dr1; ++i) x[++indice] = v[i];

    for(j; j <= dr2; ++j) x[++indice] = v[j];

    for(int k = st1; k <= dr2; ++k)

        v[k] = x[k], x[k] = 0;

}

void dei(int st, int dr){

    int m = (st + dr ) / 2;

    if(dr - st <= 0) return;

    dei(st, m);

    dei(m + 1, dr);

    interclasare(st, m, m + 1, dr);

}

int main(){

    ios::sync_with_stdio(false);

    fin.tie(0);fout.tie(0);

    int n ; fin >> n;

    for(int i = 1; i <= n; ++i){

        fin >> v[i];

    }

    dei(1, n);

    fout << rasp;

    return 0;

}
