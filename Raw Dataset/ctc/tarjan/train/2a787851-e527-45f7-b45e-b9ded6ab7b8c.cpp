#include<iostream>
#include<fstream>
#include<vector>
#include<stack>


using namespace std;



ifstream f("ctc.in");

ofstream o("ctc.out");



int id=0,n,m,cc=0,low[100010],ids[100010];

bool onStack[100010];

vector <int> v[100010],ctc[100010];

stack <int> S;

void citire(){

    f>>n>>m; int i,x,y;

    for(i=1;i<=m;i++){

        f>>x>>y;

        v[x].push_back(y);

    }

}

void dfs(int k){

    ids[k]=low[k]=++id;

    S.push(k); int i,nv;

    onStack[k]=1;

    for(i=0;i<v[k].size();i++){

        nv=v[k][i];

        if(!ids[nv]){

            dfs(nv);

            low[k]=min(low[k],low[nv]);

        }

        else if(onStack[nv]) low[k]=min(low[k],low[nv]);

    }

    if(ids[k]==low[k]){

        cc++;

        while(1){

            ctc[cc].push_back(S.top());

            onStack[S.top()]=0;

            if(S.top()==k){

                S.pop();

                return;

            }

            S.pop();

        }

    }

}

int main(){

    citire();

    int i,j;

    for(i=1;i<=n;i++)

        if(!ids[i])

            dfs(i);

    o<<cc<<'\n';

    for(i=1;i<=cc;i++){

        for(j=0;j<ctc[i].size();j++)

            o<<ctc[i][j]<<" ";

        o<<'\n';

    }

    o.close();

    f.close();

}
