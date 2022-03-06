#include <bits/stdc++.h>




using namespace std;



ifstream fin("ctc.in");

ofstream fout("ctc.out");



vector<int> G[100001];

vector<int> Gt[100001];

vector<int> compcon[100001];

int viz[100001], TSORT[100001], viz2[100001];

int n,m,k,l;



void dfs(int nod){

    viz[nod] = 1;

    for(auto vecin: G[nod]){

        if(!viz[vecin])

            dfs(vecin);

    }

    TSORT[++k] = nod;

}



void parcdfs(int nod,int comp){

    viz2[nod] = 1;

    compcon[comp].push_back(nod);

    for(auto vecin: Gt[nod]){

        if(!viz2[vecin]){

            parcdfs(vecin,comp);

        }

    }

}



int main(){

    int i,a,b;

    fin>>n>>m;

    for(i = 1; i <= m; i++){

        fin>>a>>b;

        G[a].push_back(b);

        Gt[b].push_back(a);

    }

    for(i = 1; i<= n; i++){

        if(!viz[i]){

            dfs(i);

        }

    }

    for(i = n; i >= 1; i--){

        if(!viz2[TSORT[i]]){

            l++;

            parcdfs(TSORT[i],l);

        }

    }



    fout<<l<<'\n';

    for(i = 1; i <= l; i++){

        for(auto nod: compcon[i]){

            fout<<nod<<' ';

        }

        fout<<'\n';

    }

    return 0;

}
