#include <fstream>
#include <iostream>
#include <cstring>


using namespace std;



ifstream fin ("swap.in");

ofstream fout ("swap.out");



int i, n, sol, x;

int fa[205], fb[205], f[50005];

int d[205][50005];



char a[50005], b[50005];



inline int query (int x){

    int sol = 0;

    while (x){

        sol += f[x];

        x -= (x&-x);

    }

    return sol;

}



inline void update (int x){

    while (x <= n){

        f[x]++;

        x += (x&-x);

    }

}



int main(){

    fin >> a;

    fin >> b;

    n = strlen(a);

    for (i=0; i<n; i++){

        fa[a[i]]++, fb[b[i]]++;

        d[a[i]][fa[a[i]]] = i;

    }

    for (i='a'; i<='z'; i++){

        if (fa[i] != fb[i]){

            fout << -1;

            return 0;

        }

    }

    for (i='a'; i<='z'; i++)

        fb[i] = 0;

    for (i=0; i<n; i++){

        fb[b[i]]++;

        x = query (d[b[i]][fb[b[i]]]);

        sol = sol + i - x;

        update (d[b[i]][fb[b[i]]] + 1);

    }

    fout << sol;

    return 0;

}
