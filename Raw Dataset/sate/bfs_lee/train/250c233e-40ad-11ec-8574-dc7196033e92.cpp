#include <vector>
#include <fstream>
#include <queue>
using namespace std;
#define nmax 30005
queue <int> q;
vector <pair<int,int> > adiacenta[nmax];
int n,m,x,y,dist[nmax];
bool viz[nmax];

void input(){
    ifstream fin("sate.in");
    fin>>n>>m>>x>>y;
    int n1,n2,d;
    while(fin>>n1>>n2>>d){
        adiacenta[n1].push_back({n2,d});
        adiacenta[n2].push_back({n1,d});
    }
    fin.close();
}

void bfs(int step){
    viz[step] = 1;
    dist[step] = 0;
    q.push(step);
    while(!q.empty()){
        int nod = q.front();
        q.pop();
        for(auto i : adiacenta[nod]){
            if(!viz[i.first]){
                viz[i.first] = 1;
                if(nod < i.first){
                    dist[i.first] = dist[nod] + i.second;
                    q.push(i.first);
                }
                else {
                    dist[i.first] = dist[nod] - i.second;
                    q.push(i.first);
                }
            }
        }

    }
}

int main()
{
    ofstream fout("sate.out");
    input();
    bfs(x);
    fout<<dist[y];
    fout.close();
    return 0;
}
