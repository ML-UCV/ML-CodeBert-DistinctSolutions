#include <fstream>
#include <queue>
#include <vector>

using namespace std;
ifstream fin ("sate.in");
ofstream fout ("sate.out");

vector < pair < int, int > > graf[30002];
queue < int > q;
int cost [30002];


void BFS (int $$, int $$$){

 vector < pair < int, int > > :: iterator it;
 q.push($$);
 cost[$$] = 1;
 while (!q.empty()){
    int nod = q.front();
    q.pop();
    for (it = graf[nod].begin(); it != graf[nod].end(); ++it){
      if (cost[it->first] == 0) {
        cost[it->first] = cost[nod] + it->second;

      if (it->first == $$$) return ;
      q.push(it->first);
      }
    }
 }
}

int main (){


  int n,m,x,y;
  int $$, $$$, $$$$;
  fin >> n >> m >> x >> y;
  for (int i = 1; i <= m; ++i){
    fin >> $$ >> $$$ >> $$$$;
    graf[$$].push_back(make_pair($$$,$$$$));
    graf[$$$].push_back(make_pair($$,-$$$$));
  }
  BFS(x,y);
  fout << cost[y]-1 << "\n";

}
