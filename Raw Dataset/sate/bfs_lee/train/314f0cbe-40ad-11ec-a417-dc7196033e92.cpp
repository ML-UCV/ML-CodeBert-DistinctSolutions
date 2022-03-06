#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
 
 
#define maxim 30005
 
using namespace std;
 
bool viz[maxim];
int v[maxim];
vector <pair<int,int> > G[maxim];
queue <int> q;
int n;
int nrdist[maxim];
 
 
 
 
int main()
{
    int x,y,i,a,b,k,m,l,cont,nod,nod2;
    ifstream  f("sate.in");
    ofstream  g("sate.out");
    f >> n >> m >> a >> b;
    for (i=1;i<=m;i++){
        f >> x >> y >> l;
        G[x].push_back(make_pair(y,l));
        G[y].push_back(make_pair(x,-l));
    }
    q.push(a);
    v[a]=0;
    while(!q.empty()){
        nod=q.front();
        q.pop();
        x=G[nod].size();
        for (i=0;i<x;i++){
            if (!viz[G[nod][i].first]){
                q.push(G[nod][i].first);
                viz[G[nod][i].first]=true;
                v[G[nod][i].first]=v[nod]+G[nod][i].second;
            }
        }
    }
    g << v[b];
}
