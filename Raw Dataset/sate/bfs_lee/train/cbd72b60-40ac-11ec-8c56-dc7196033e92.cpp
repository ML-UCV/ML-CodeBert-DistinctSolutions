#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
using namespace std;
const int maxi = 100010;
vector<pair<int, int>> lista[maxi];
int g[maxi], vizitat[maxi], distante[maxi];
queue<int> coada;

 void bfs(int start) {
    int j;
    coada.push(start);
   while(!coada.empty()) {
       int nodCurent = coada.front();
       coada.pop();
       for(j = 0; j < g[nodCurent]; ++j) {
           pair<int, int> nod = lista[nodCurent][j];
           if (vizitat[nod.first] == 0) {
               distante[nod.first] = distante[nodCurent] + nod.second;
               vizitat[nod.first] = 1;
               coada.push(nod.first);
           }
       }
   }
 }

int main() {
    ifstream fin("sate.in");
    ofstream fout("sate.out");
    int n, m, i, x, y,start, c, stop;
    fin >> n >> m >> start >> stop;
    for(i = 1; i <= m; ++i) {
        fin >> x >> y >> c;
        lista[x].emplace_back(y, c);
        lista[y].emplace_back(x, -c);
    }
    for(i = 1; i <= n; ++i)
        g[i] = lista[i].size();
    bfs(start);
    fout << distante[stop];
    return 0;
}