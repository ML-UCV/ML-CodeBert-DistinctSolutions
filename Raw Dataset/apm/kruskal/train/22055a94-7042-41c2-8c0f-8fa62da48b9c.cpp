#include <bits/stdc++.h>


using namespace std;



const int NMAX=2e5+5,MMAX=4e5+5;

int n,m;

vector<pair<int,int>> tree;



ifstream fin("apm.in");

ofstream fout("apm.out");



struct nod

{

    int parent;

    int depth;

    int cost;

} graph[NMAX];



struct edge

{

    int x,y,cost;

    bool operator<(edge a)

    {

        if(a.cost==cost)

            return x<a.x;

        return cost<a.cost;

    }

} edges[MMAX];



int findroot(int x)

{

    if(graph[x].parent==0)

        return x;

    int parent=findroot(graph[x].parent);

    graph[x].parent=parent;

    return parent;

}



void read()

{

    fin>>n>>m;

    for(int i=0; i<m; i++)

        fin>>edges[i].x>>edges[i].y>>edges[i].cost;

    sort(edges,edges+m);

}



void reunion(int r1,int r2,int i)

{

    if(graph[r1].depth==graph[r2].depth)

    {

        graph[r1].cost+=graph[r2].cost+edges[i].cost;

        graph[r2].parent=r1;

        graph[r1].depth++;

    }

    else if(graph[r1].depth>graph[r2].depth)

    {

        graph[r1].cost+=graph[r2].cost+edges[i].cost;

        graph[r2].parent=r1;

    }

    else

    {

        graph[r2].cost+=graph[r1].cost+edges[i].cost;

        graph[r1].parent=r2;

    }

}



void Kruskal()

{

    for(int i=0; i<m; i++)

    {

        int r1=findroot(edges[i].x),r2=findroot(edges[i].y);



        if(r1!=r2)

        {

            reunion(r1,r2,i);

            tree.emplace_back(edges[i].x,edges[i].y);

        }

    }

}



void print()

{

    fout<<graph[findroot(1)].cost<<"\n"<<n-1<<"\n";

    for(auto it: tree)

        fout<<it.first<<" "<<it.second<<"\n";

}



int main()

{

    read();

    Kruskal();

    print();

    return 0;

}
