#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;



ifstream f("apm.in");

ofstream o("apm.out");



int n,m,rang[200001],t[200001],s[400001],sol,nr;

pair<int,pair<int,int> > g[400001];



void read(){

    int i;

    f >> n >> m;

    for(i=1;i<=m;++i)

        f >> g[i].second.first >> g[i].second.second >> g[i].first;

    sort(g+1,g+1+m);

}



int multime(int nod){

    if(t[nod]!=nod)

        t[nod]=multime(t[nod]);

    return t[nod];

}



void join(int i,int j){

    i=multime(i);

    j=multime(j);

    if(i==j) return;



    if(rang[i]<rang[j]) t[i]=j;

    else t[j]=i;

    if(rang[i]==rang[j]) ++rang[i];

}



void apm(){

    int k,i,j,cost;

    for(k=1;k<=m;++k)

        t[k]=k;

    for(k=1;k<=m;++k){

        i=g[k].second.first;

        j=g[k].second.second;

        cost=g[k].first;

        if(multime(i)!=multime(j)){

            join(i,j);

            sol+=cost;

            s[++nr]=k;

        }

    }

}



void afis(){

    int i,k;

    o << sol << '\n' << n-1 << '\n';

    for(i=1;i<=nr;++i){

        k=s[i];

        o << g[k].second.first << " " << g[k].second.second << '\n';

    }

}



int main()

{

    read();

    apm();

    afis();



    return 0;

}
