#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>


const int NMAX=200001;



struct Muchie{

    int x,y,cost;

}aux;



std::ofstream out("apm.out");

std::ifstream in("apm.in");



std::vector<Muchie>muchii,sol;

int tata[NMAX],h[NMAX];



int getRoot(int x){

     while(x!=tata[x])

        x=tata[x];

     return x;

}



void unionSet(int x,int y){

    if(h[x]<h[y])

        tata[x]=y;

    else if(h[x]>h[y])

        tata[y]=x;

    else tata[y]=x,h[x]++;

}



int main(){

    int n,m,suma=0;

    in>>n>>m;

    for(int i=1;i<=n;i++)

        tata[i]=i,h[i]=1;

    for(int i=1;i<=m;i++)

        in>>aux.x>>aux.y>>aux.cost,muchii.push_back(aux);

    std::sort(muchii.begin(),muchii.end(),

              [](const Muchie & a,const Muchie &b){

                    return a.cost<b.cost;

              });

    for(auto mx:muchii){

        if(getRoot(mx.x)!=getRoot(mx.y))

            unionSet(getRoot(mx.x),getRoot(mx.y)),sol.push_back(mx),suma+=mx.cost;

        if(sol.size()==n-1)

            break;

    }

    out<<suma<<'\n'<<n-1<<'\n';

    for(auto mx:sol)

        out<<mx.x<<" "<<mx.y<<'\n';

    return 0;

}
