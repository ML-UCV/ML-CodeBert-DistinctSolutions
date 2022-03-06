#include<iostream>
#include<fstream>
#include<vector>
#include<stack>
using namespace std;

vector <int> v[100010],vt[100010],cc[100010];

stack <int> S;

int n,ctc=0; bool viz[100010],vizt[100010];

void citire(){

    int i,m,x,y; ifstream f("ctc.in");

    f>>n>>m;

    for(i=1;i<=m;i++){

        f>>x>>y;

        v[x].push_back(y);

        vt[y].push_back(x);

    }

}

void dfs(int k){

    viz[k]=1; int i,nv;

    for(i=0;i<v[k].size();i++){

        nv=v[k][i];

        if(!viz[nv]) dfs(nv);

    }

    S.push(k);

}

void dfs2(int k){

    vizt[k]=1; int i,nv;

    cc[ctc].push_back(k);

    for(i=0;i<vt[k].size();i++){

        nv=vt[k][i];

        if(!vizt[nv]) dfs2(nv);

    }

}

int main(){

    int i,j; ofstream o("ctc.out");

    citire();

    for(i=1;i<=n;i++)

        if(!viz[i]) dfs(i);

    while(S.size()){

        if(!vizt[S.top()]){

            ctc++;

            dfs2(S.top());

        }

        S.pop();

    }

    o<<ctc<<"\n";

    for(i=1;i<=ctc;i++){

        for(j=0;j<cc[i].size();j++)

            o<<cc[i][j]<<" ";

        o<<"\n";

    }

    return 0;

}
