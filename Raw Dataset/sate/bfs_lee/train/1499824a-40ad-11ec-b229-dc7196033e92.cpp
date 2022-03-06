#include <fstream>
#include <queue>
#include <vector>
#define mp make_pair
using namespace std;

ifstream fin("sate.in");
ofstream fout("sate.out");

vector <pair<int,int> > vecini[3*(int)1e4+10];
queue<int> q;
int distanta[(int)1e5];
int x,y;

int bfs(){
    q.push(x);
    int i;
    while(!q.empty()){
        if(q.front() == y){
            return distanta[q.front()];
        }
        int nod = q.front();
        q.pop();
        for(i = 0; i < vecini[nod].size(); i++){
            if(!distanta[vecini[nod][i].first]){
                if(nod < vecini[nod][i].first){
                    distanta[vecini[nod][i].first] = distanta[nod]+vecini[nod][i].second;
                }
                else{
                    distanta[vecini[nod][i].first] = distanta[nod]-vecini[nod][i].second;
                }
                q.push(vecini[nod][i].first);
            }
        }
    }
}

int main(){

    int n,m,nr1,nr2;
    fin>>n>>m>>x>>y;
    int i,j;
    for(i = 1; i <= m; i++){
        fin>>nr1>>nr2>>j;
        vecini[nr1].push_back(mp(nr2,j));
        vecini[nr2].push_back(mp(nr1,j));
    }

    fout<<bfs();

}
