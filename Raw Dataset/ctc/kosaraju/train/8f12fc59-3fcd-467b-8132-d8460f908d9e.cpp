#include <bits/stdc++.h>


using namespace std;



ifstream f("ctc.in");

ofstream g("ctc.out");



vector < int > G[100001], GT[100001], ass[100001];

stack < int > S;

int n, m, nr, v[100001];



void citire(){

    int x, y;

    f >> n >> m;

    for(int i = 0; i <= m; i ++){

        f >> x >> y;

        G[x].push_back(y);

        GT[y].push_back(x);

    }

}



void dfsG(int k){

    v[k] = 1;

    for(auto x: G[k])

        if(v[x] == 0)

            dfsG(x);

    S.push(k);

}



void dfsGT(int k){

    v[k] = -1;

    ass[nr].push_back(k);

    for(auto x: GT[k])

        if(v[x] == 1)

            dfsGT(x);

}



void rezolvare(){

    for(int i = 1; i <= n; i ++)

        if(!v[i])

            dfsG(i);



    while(!S.empty()){

        int nod = S.top();

        if(v[nod] == 1){

            nr ++;

            dfsGT(nod);

        }

        S.pop();

    }

    g << nr << '\n';

    for(int i = 1; i <= nr; i ++){

        sort(ass[i].begin(), ass[i].end());

        for(int j = 0; j < ass[i].size(); j ++)

            g << ass[i][j] << ' ';

        g << '\n';

    }

}





int main(){

    citire();

    rezolvare();

}
