#include<iostream>
#include<fstream>
#include<vector>
#include<stack>
using namespace std;

int n,id=0,ids[100010],low[100010],ctc=0;

ofstream o("ctc.out");

ifstream f("ctc.in");

vector <int> v[100010],cc[100010];

stack <int> S;

bool onStack[100010],viz[100010];

void dfs(int k){

    ids[k]=low[k]=++id; int i,nv;

    S.push(k); onStack[k]=1;

    viz[k]=true;

    for(nv=0;nv<v[k].size();nv++){

        i=v[k][nv];

        if(!viz[i]){

            dfs(i);

            low[k]=min(low[k],low[i]);

        }

        else if(onStack[i]) low[k]=min(low[k],low[i]);

    }

    if(ids[k]==low[k]){

        ctc++;

        while(1){

            cc[ctc].push_back(S.top());

            onStack[S.top()]=0;

            if(S.top()==k){

                S.pop();

                break;

            }

            S.pop();

        }

    }

}

int main(){

    int m,x,y,i,j;

    f>>n>>m;

    for(i=1;i<=m;i++){

        f>>x>>y;

        v[x].push_back(y);

    }



    for(i=1;i<=n;i++)

        if(!viz[i]) dfs(i);



    o<<ctc<<"\n";

    for(i=1;i<=ctc;i++){

        for(j=0;j<cc[i].size();j++)

            o<<cc[i][j]<<" ";

        o<<"\n";

    }

    return 0;

}
