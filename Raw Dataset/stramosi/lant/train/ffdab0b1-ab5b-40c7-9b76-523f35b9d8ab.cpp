#include <bits/stdc++.h>


using namespace std;



ifstream fin("stramosi.in");

ofstream fout("stramosi.out");



int TT[250005];

int neFr[250005];

int Fr[250005];

int h[250005];

vector<int> G[250005];

int fr;



void parinte(int nod){

    Fr[nod] = fr;

    while(nod != 0){

        h[TT[nod]] = h[nod] + 1;

        Fr[nod] = fr;

        G[fr].push_back(nod);

        nod = TT[nod];

    }

}



int main ()

{

    int n,m,i,a,b,poz;

    fin>>n>>m;

    for(i = 1; i <= n; i++){

        fin>>TT[i];

        neFr[TT[i]] = 1;

    }

    for(i = 1; i <= n; i++){

        if(neFr[i] == 0){

            fr = i;

            parinte(i);

        }

    }

    for(i = 1; i <= m; i++){

        fin>>a>>b;

        poz = b + h[a];

        if(poz >= G[Fr[a]].size()){

            fout<<'0'<<'\n';

        }else{

            fout<<G[Fr[a]][poz]<<'\n';

        }

    }

    return 0;

}
