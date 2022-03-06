#include <fstream>
#include <vector>
#include <queue>

std::ifstream in("sate.in");
std::ofstream out("sate.out");

const int N = 3e4+1;
std::vector<std::pair<int,int>> g[N];
bool vis[N];
int res, x, y;

void bfs(int i){
    std::queue<std::pair<int,int>> q;
    q.push({i,0});
    vis[i] = 1;
    while(!q.empty()){
        int currNode = q.front().first, currDist = q.front().second;
        q.pop();
        for(auto node : g[currNode]){
            if(vis[node.first]) continue;
            int dist = (node.first > currNode ? node.second : -node.second);
            vis[node.first] = 1;
            if(node.first == y){
                res = currDist + dist;
                return;
            }
            q.push({node.first, currDist + dist});
        }
    }
}   

int main(){
    int n,m;
    in>>n>>m>>x>>y;
    for(int i=0;i<m;++i){
        int a, b, dist;
        in>>a>>b>>dist;
        g[a].push_back({b,dist});
        g[b].push_back({a,dist});
    }
    bfs(x);
    out<<res;
    in.close();
    out.close();
    return 0;
}
