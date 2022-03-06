#include <fstream>
#include <queue>
#include <vector>
#include <string>

std::ifstream f("sate.in");
std::ofstream g("sate.out");

const int NMAX = 30'005;
int n,m,nodStart,nodEnd,cost,x,y,d[NMAX];
bool vis[NMAX];

std::string s;
std::queue<int>Q;
std::vector<std::pair<int,int>>L[NMAX];

void bfs(int nod){
    
    Q.push(nod);
    vis[nod] = true;
    
    while(!Q.empty()){
        
        int nod = Q.front();
        Q.pop();
        
        for(int i = 0;i < L[nod].size();++i){
            
            int vecin = L[nod][i].first;
            int cost = L[nod][i].second;
            
            if(!vis[vecin]){
                vis[vecin] = true;
                d[vecin] = d[nod] + cost;
                Q.push(vecin);
            }
        }
    }
}

int main(){
    
    f >> n >> m >> nodStart >> nodEnd;
    f.get();
    
    for(int i = 1;i <= m;++i){
        
        std::getline(f,s);
        
        int j = 0;
        x = y = cost = 0;
        
        while(s[j] >= '0' && s[j] <= '9')
            x = x * 10 + (s[j++] - '0');
        
        j++;
        while(s[j] >= '0' && s[j] <= '9')
            y = y * 10 + (s[j++] - '0');
        
        j++;
        while(s[j] >= '0' && s[j] <= '9')
            cost = cost * 10 + (s[j++] - '0');
        
        L[x].push_back({y,cost});
        L[y].push_back({x,-cost});
    }
    
   bfs(nodStart);
    
   g << d[nodEnd];
    
    return 0;
}
