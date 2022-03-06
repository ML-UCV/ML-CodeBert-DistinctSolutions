#include <fstream>
#include <vector>
#include <queue>

using namespace std;
ifstream f("sate.in");
ofstream g("sate.out");
const int N=3e4+1;
int n,m,x,y;
int d[N];
vector <pair <int,int>> a[N];

void bfs(){
    queue <int> q;
    q.push(x);
    d[x]=0;
    while(!q.empty()){
        int p=q.front();
        q.pop();
        for(pair <int,int> j:a[p]){
            if(d[j.first]==-1){
               if(j.first<p)
                d[j.first]=d[p]-j.second;
               else
                d[j.first]=d[p]+j.second;
               q.push(j.first);
            }
        }
    }
}

int main()
{
    f>>n>>m>>x>>y;
    for(int i=1; i<=m; i++){
        int p,t,d;
        f>>p>>t>>d;
        a[p].push_back({t,d});
        a[t].push_back({p,d});
    }
    for(int i=1; i<=n; i++)
       d[i]=-1;
    bfs();
    g<<d[y];
    return 0;
}
