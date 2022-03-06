#include <iostream>
#include <fstream>
#include <queue>
#include <vector>

using namespace std;

ifstream in("sate.in");
ofstream out("sate.out");

int d[30001];

vector <pair<int, int>> a[30001];

queue <int> coada;

void bfs(int s)
{
   coada.push(s);
   while(!coada.empty()){
       int x=coada.front();
       coada.pop();
       for(auto y:a[x])
           if(d[y.first]==0){
               d[y.first]=d[x]+y.second;
               coada.push(y.first);
           }
   }
}

int main()
{
    int n,m,st,fin;
    in>>n>>m>>st>>fin;
    for(int i=1;i<=m;i++){
        int dist,x,y;
        in>>dist>>x>>y;
        a[dist].push_back({x,y});
        a[x].push_back({dist,-y});
    }
    bfs(st);
    out<<d[fin]<<'\n';
    return 0;
}
