#include <bits/stdc++.h>
#define NMAX 30005
using namespace std;

ifstream f("sate.in");
ofstream g("sate.out");

vector < pair < int, int > > nod[NMAX];
queue < int > q;

int n, m, x, y, D, start, stop, ans, drum[NMAX];
bool visited[NMAX];

void citire(){
    f>>n>>m>>start>>stop;
    for(int i = 1; i <= m; ++i){
        f>>x>>y>>D;
        nod[x].push_back(make_pair(y, D));
        nod[y].push_back(make_pair(x, -D));
    }
}

void bfs(){
    q.push(start);
    visited[start] = 1;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto &i : nod[node]){
            int beside = i.first;
            int val = i.second;
            if(!visited[beside]){
                drum[beside] = drum[node] + val;
                visited[beside] = 1;
                q.push(beside);
                if(beside == stop){
                    g<<drum[stop];
                    break;
                }
            }
        }

    }

}

int main()
{
    citire();
    bfs();
    return 0;
}
