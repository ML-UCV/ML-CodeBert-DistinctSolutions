#include <bits/stdc++.h>


using namespace std;

ifstream f("ctc.in");

ofstream g("ctc.out");

vector <int> G[100001];

vector <int> GT[100001];

vector <int> rezultat[100001];

stack < int > stiva;

int n,m,a,b,viz[100001],nrctc;

int dfs(int i){

    viz[i]=1;

    for(auto j:G[i]){

        if(viz[j]==0){

            dfs(j);

        }

    }

    stiva.push(i);

}

int dfst(int i){

    viz[i]=2;



    rezultat[nrctc].push_back(i);

    for(auto j:GT[i]){

        if(viz[j]==1){

            dfst(j);

        }

    }



}

int main()

{

    f>>n>>m;

    for(int i=1;i<=m;i++){

        f>>a>>b;

        G[a].push_back(b);

        GT[b].push_back(a);

    }



    for(int i=1;i<=n;i++){

        if(viz[i]==0)dfs(i);

    }







    while(!stiva.empty()){

           int i=stiva.top();



            if(viz[i]==1){

                nrctc++;

                dfst(i);

            }

            stiva.pop();



    }

    g<<nrctc<<'\n';;

    for(int i=1;i<=nrctc;i++){

        for(auto j:rezultat[i]){

            g<<j<<" ";

        }

        g<<'\n';

    }



}
