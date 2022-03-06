#include <istream>
#include <fstream>
#include <queue>
#include <vector>

using namespace std;
int n,m,x,y,dist[30001],viz[30001];
vector<pair<int,int> >adiacenta[30001];
queue<int> q;

ifstream f("sate.in");
ofstream g("sate.out");

void BFS(){
    while(!q.empty()){
        int y=q.front();
        q.pop();
        for(auto i:adiacenta[y]){
            if(viz[i.first]==0){
                viz[i.first]=1;
                if(y<i.first){
                    q.push(i.first);
                    dist[i.first]=dist[y]+i.second;
                }
                else{
                    q.push(i.first);
                    dist[i.first]=dist[y]-i.second;
                }
            }
        }
    }
}

int main(){
    f>>n>>m>>x>>y;
    for(int i=1;i<=m;i++){
        int a,b,c;
        f>>a>>b>>c;
        adiacenta[a].push_back(make_pair(b,c));
        adiacenta[b].push_back(make_pair(a,c));
    }
    q.push(x);
    BFS();
    g<<dist[y];
}
