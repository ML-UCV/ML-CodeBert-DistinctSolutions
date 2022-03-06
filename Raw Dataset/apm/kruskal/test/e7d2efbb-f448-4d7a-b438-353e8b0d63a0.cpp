#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

ifstream be("apm.in");

ofstream ki("apm.out");



const int NMAX=200000;



int findset(int i,vector<int>&parent)

{

    if(i==parent[i])

        return i;

    else{

        int root=findset(parent[i],parent);

        parent[i]=root;

        return root;

    }



}



void unionset(int x,int y,vector<int>&parent,vector<int>&rank)

{

    int rx=findset(x,parent);

    int ry=findset(y,parent);

    if(rank[rx]<rank[ry])

        parent[rx]=ry;

    else if(rank[rx]==rank[ry]){

        rank[ry]++;

        parent[rx]=ry;

    }

    else parent[ry]=rx;







}



void kruskal(vector<pair<int,pair<int,int> > >&adj,vector<pair<int,int> >&t,vector<int>&parent,vector<int>&rank,int &db,int &m,int &k)

{

    int xRep,yRep;

    sort(adj.begin(),adj.end());

    for(int i=0;i<m;i++)

    {

        xRep=findset(adj[i].second.first,parent);

        yRep=findset(adj[i].second.second,parent);

        if(xRep!=yRep)

        {

            t[k++] = {adj[i].second.first,adj[i].second.second};

            db+=adj[i].first;

            unionset(xRep,yRep,parent,rank);

        }

    }



}



int main()

{

    int n,m,db=0,k=0;

    be>>n>>m;

    vector<pair<int,pair<int,int> > >adj;

    for(int i=0;i<m;i++)

    {

        int x,y,c;

        be>>x>>y>>c;

        adj.push_back({c,{x,y}});

    }

    vector<int>parent(n+1);

    vector<int>rank(n+1,0);

    for(int i=1;i<=n;i++)

        parent[i]=i;

    vector<pair<int,int> >t(NMAX);

    kruskal(adj,t,parent,rank,db,m,k);

    ki<<db<<endl;

    ki<<k<<endl;

    for(int i=0;i<k;i++)

    {

        ki<<t[i].second<<" "<<t[i].first<<endl;

    }



    return 0;

}
