#include <fstream>
#include <vector>
#include <queue>

using namespace std;

ifstream in("sate.in");
ofstream out("sate.out");

typedef pair <int, int> p;
const int NMAX = 30005;
vector <p> G[NMAX];
int N, M, X, Y;
bool use[NMAX];
queue <p> q;

void Read(){
    in >> N >> M >> X >> Y;
    for(int i = 1; i <= M; ++i){
        int a, b, d;
        in >> a >> b >> d;
        G[a].push_back(make_pair(b, d));
        G[b].push_back(make_pair(a, d));
    }
    q.push(make_pair(X, 0));
    use[X] = true;
}

void SolveAndPrint(){
    while(!q.empty()){
        int node = q.front().first;
        int cost = q.front().second;
        if(node == Y){
            out << cost << "\n";
            break;
        }
        q.pop();
        for(int i = 0; i < G[node].size(); ++i){
            p neighbour = G[node][i];
            if(!use[neighbour.first]){
                use[neighbour.first] = true;
                q.push(make_pair(neighbour.first,
                       cost + (neighbour.second * (node < neighbour.first ? 
                       1 : -1))));
            }
        }
    } 
}

int main(){
    Read();
    SolveAndPrint();
}
