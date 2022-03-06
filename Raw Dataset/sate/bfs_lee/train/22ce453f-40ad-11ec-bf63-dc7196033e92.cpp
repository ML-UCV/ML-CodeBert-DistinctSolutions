#include <fstream>
#include<vector>
#include<queue>
using namespace std;
#define NMAX 30005

ifstream fin("sate.in");
ofstream fout("sate.out");

struct elem{
    int nod, dist;
};
int n, m, x, y, d[NMAX];
vector <elem> g[NMAX];
bool viz[NMAX];

void citire(){
    int v1, v2, lungime;
    fin>>n>>m>>x>>y;
    for(int i=1;i<=m;i++){
        fin>>v1>>v2>>lungime;
        if(v1>v2)lungime=-lungime;
        g[v1].push_back({v2,lungime});
        g[v2].push_back({v1,-lungime});

    }
}

int bfs(int x,int y){
    queue <int> q;
     q.push(x);
     viz[x]=1;
     while(!q.empty()){
            int v2, v1 = q.front();
            q.pop();
            for(unsigned int i=0;i<g[v1].size();i++){
                v2=g[v1][i].nod;
                if( !viz[v2] ){
                    d[v2]=d[v1]+g[v1][i].dist;

                    if(v2==y) return d[v2];

                    viz[v2]=1;
                    q.push(v2);
                }
            }
    }
    return 0;
}

int main()
{
    citire();
    fout<<bfs(x,y);
    return 0;
}
