#include<iostream>
#include<fstream>
#include<vector>
#include<stack>


using namespace std;



ifstream f("ctc.in");

ofstream o("ctc.out");



int n,m,cc=0;

bool viz[100010],vizt[100010];

vector <int> v[100010],vt[100010],ctc[100010];

stack <int> S;



void citire(){

    f>>n>>m; int x,y,i;

    for(i=1;i<=m;i++){

        f>>x>>y;

        v[x].push_back(y);

        vt[y].push_back(x);

    }

}

void dfs1(int k){

    viz[k]=1;

    int i;

    for(i=0;i<v[k].size();i++)

        if(!viz[v[k][i]])

            dfs1(v[k][i]);

     S.push(k);

}

void dfs2(int k){

    vizt[k]=1;

    int i; ctc[cc].push_back(k);

    for(i=0;i<vt[k].size();i++)

        if(!vizt[vt[k][i]])

            dfs2(vt[k][i]);

}

int main(){

    citire();

    int i,j;

    for(i=1;i<=n;i++)

        if(!viz[i])

            dfs1(i);

    while(S.size()){

        if(!vizt[S.top()]){

            cc++;

            dfs2(S.top());

        }

        S.pop();

    }

    o<<cc<<'\n';

    for(i=1;i<=cc;i++){

        for(j=0;j<ctc[i].size();j++)

            o<<ctc[i][j]<<" ";

        o<<'\n';

    }

    o.close();

    f.close();

}
