#include <bits/stdc++.h>


using namespace std;

const int MAXN = 3 * 1e5;

int father[35][MAXN];

int fth(int x, int node){

    for(int i = 0 ; (1 << i) <= x; ++i){

        if(x & (1 << i)) node = father[i][node];

    }

    return node;

}

ifstream fin("stramosi.in");

ofstream fout("stramosi.out");

int main(){

    int n, m;

    fin >> n >> m;

    for(int i = 1; i <= n; ++i){

        int x;

        fin >> x;

        father[0][i] = x;

    }

    for(int node = 1; node <= n; ++node){

        for(int i = 1; i <= 29; ++i){

            father[i][node] = father[i - 1][father[i - 1][node]];

        }

    }

    for(int i = 1; i <= m; ++i){

        int p, q;

        fin >> q >> p;

        fout << fth(p, q) << '\n';

    }

    return 0;

}
