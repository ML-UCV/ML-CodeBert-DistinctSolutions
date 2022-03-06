#include <bits/stdc++.h>


using namespace std;



ifstream in("ctc.in");

ofstream out("ctc.out");



vector < int > g[100005], gt[100005], sol[100005];

stack < int > st;

int c[100005], n, m, x, y, nrctc;





void dfs1(int k){

    c[k] = 1;

    for(int i = 0; i < g[k].size(); i++){

        int vec = g[k][i];

        if(!c[vec])

            dfs1(vec);

    }

    st.push(k);

}





void dfs2(int k){

    c[k] = 2;

    sol[nrctc].push_back(k);

    for(int i = 0; i < gt[k].size(); i++){

        int vec = gt[k][i];

        if(c[vec] == 1)

            dfs2(vec);

    }

}



void Kosaraju(){

    for(int i = 1; i <= n; i++)

        if(!c[i])

            dfs1(i);



    while(!st.empty()){

        int nod = st.top();

        if(c[nod] == 1){

            nrctc++;

            dfs2(nod);

        }

        st.pop();

    }



}



int main(){

    in>>n>>m;

    for(int i = 1; i <= m; i++){

        in>>x>>y;

        g[x].push_back(y);

        gt[y].push_back(x);

    }

    Kosaraju();



    out<<nrctc<<"\n";

    for(int i = 1; i <= nrctc; i++, out<<"\n")

        for(int j = 0; j < sol[i].size(); j++)

            out<<sol[i][j]<<" ";

}
