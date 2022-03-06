#include <fstream>
#include <iostream>
#include <vector>
using namespace std;



int sol[300], v[300];

vector<int> L[300];



int n, m, nr, index, lev[300], low[300], st[300], varf, x, y, z, in[300], is[300];



inline int Minus(int x) {

    if (x <= n)

        return n+x;

    else

        return x-n;

}



void tarjan(int nod) {

    index ++;

    lev[nod] = index;

    low[nod] = index;

    st[++varf] = nod;

    v[nod] = 1;

    is[nod] = 1;

    for (int i=0;i<L[nod].size();i++) {

        int vecin = L[nod][i];

        if (v[vecin] == 0) {

            tarjan(vecin);

            low[nod] = min(low[nod], low[vecin]);

        } else

            if (is[vecin])

                low[nod] = min(low[nod], low[vecin]);

    }



    if (low[nod] == lev[nod]) {

        do {

            x = st[varf--];

            is[x] = 0;

            if (sol[x] == 0) {

                sol[x] = 1;

                sol[Minus(x)] = 2;

            }



        } while(x != nod);

    }



}





int main () {

    ifstream fin ("party.in");

    ofstream fout("party.out");



    fin>>n>>m;

    for (int i=1;i<=m;i++) {

        fin>>x>>y>>z;

        if (z == 0) {

            L[Minus(x)].push_back(y);

            L[Minus(y)].push_back(x);

            in[x] = 1;

            in[y] = 1;

        } else

            if (z == 1) {

                L[Minus(x)].push_back(Minus(y)), in[ Minus(y) ] = 1;

                L[y].push_back(x), in[ x ] = 1;

            }

            else

                if (z == 2) {

                    L[Minus(y)].push_back(Minus(x)), in[ Minus(x) ] = 1;

                    L[x].push_back(y), in[ y ] = 1;

                } else {

                    L[x].push_back(Minus(y)), in[Minus(y)] = 1;

                    L[y].push_back(Minus(x)), in[Minus(x)] = 1;

                }

    }



    for (int i=1;i<=n+n;i++)

        if (v[i] == 0) {

            tarjan(i);

        }



    for (int i=1;i<=n;i++)

        if (sol[i] == 1) {

            nr++;

        }



    fout<<nr<<"\n";

    for (int i=1;i<=n;i++)

        if (sol[i] == 1) {

            fout<<i<<"\n";

        }

    return 0;

}
