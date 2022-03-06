#include <bits/stdc++.h>




using namespace std;



ifstream f("ctc.in");

ofstream g("ctc.out");



vector <int> v1[100001], v2[100001], v3[100001];



int st[100001];

int n,m,x,y,k,nr;



bool ap[100001], ap2[100001];



void DFS(int node){

    ap[node]=1;

    for(int i=0; i<v1[node].size(); ++i){

        if(!ap[v1[node][i]])

            DFS(v1[node][i]);

    }

    st[++k]=node;

}



void DFS2(int node){

    ap2[node]=1;

    for(int i=0; i<v2[node].size(); ++i){

        if(!ap2[v2[node][i]]){

            DFS2(v2[node][i]);

        }

    }

    v3[nr].push_back(node);

}





void ctc(int n){

    for(int i=1; i<=n; ++i){

        if(!ap[i])

            DFS(i);

    }

    for(int i=n; i>0; --i){

        if(!ap2[st[i]]){

            ++nr;

            DFS2(st[i]);

        }

    }

}



int main(){

    f>>n>>m;



    for(int i=1; i<=m; ++i){

        f>>x>>y;

        v1[x].push_back(y);

        v2[y].push_back(x);

    }



    ctc(n);

    g<<nr<<'\n';

    for(int i=1; i<=nr; ++i){

        sort(v3[i].begin(), v3[i].end());

        for(int j=0; j<v3[i].size(); ++j)

            g<<v3[i][j]<<' ';

        g<<'\n';

    }



    return 0;

}
