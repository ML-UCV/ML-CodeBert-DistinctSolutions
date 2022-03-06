#include <bits/stdc++.h>
#define NMAX 30003
using namespace std;
ifstream fin ("sate.in");
ofstream fout ("sate.out");
vector <pair <int, int> >v [NMAX];
queue <int> q;
int n, m, x, y, a, b, c;
int dist [NMAX], viz [NMAX];
void bfs (int nod){
    q.push (nod);
    viz [nod] = 1;
    while (!q.empty ()){
        int nod = q.front ();
        q.pop ();
        for (auto A : v [nod]){
            if (!viz [A.first]){
                q.push (A.first);
                viz [A.first] = 1;
                if (nod > A.first)
                    dist [A.first] = dist [nod] - A.second;
                else dist [A.first] = dist [nod] + A.second;
                if (A.first == y){
                    fout << dist [y];
                    return ;
                }
            }
        }
    }
}
int main (){
    fin >> n >> m >> x >> y;
    for (int i = 1; i <= m; i ++){
        fin >> a >> b >> c;
        v [a].push_back ({b, c});
        v [b].push_back ({a, c});
    }
    bfs (x);
    return 0;
}
