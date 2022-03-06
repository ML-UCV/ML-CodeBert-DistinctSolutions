#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
int N, M, X, Y, i, j, k;
char C[50];
struct Str{
    int node;
    int cost;
};
Str make_str(int a, int b){
    Str S;
    S.node=a; S.cost=b;
    return S;
}
queue<Str> Q;
vector<vector<Str> > Graph(30001);
bool Check[30001];
void BFS();
int Parse();
int main()
{
    freopen("sate.in", "r", stdin);
    freopen("sate.out", "w", stdout);
    fgets(C, 50, stdin);
    k=-1; N=Parse(); M=Parse(); X=Parse(); Y=Parse();
    for(i=1; i<=N; ++i) Graph[i].push_back(make_str(0, 0));
    for(i=1; i<=M; ++i){
        int x, y, z;
        fgets(C, 50, stdin);
        k=-1; x=Parse(); y=Parse(); z=Parse();
        Graph[x].push_back(make_str(y, z));
        Graph[y].push_back(make_str(x, z));
        ++Graph[x][0].node;
        ++Graph[y][0].node;
    }
    BFS();
    return 0;
}
void BFS(){
    Q.push(make_str(X, 0));
    Check[X]=true;
    while(!Q.empty()){
        Str i=Q.front();
        Q.pop();
        int j;
        for(j=1; j<=Graph[i.node][0].node; ++j)
            if(Check[Graph[i.node][j].node]==false){
            if(Graph[i.node][j].node==Y){printf("%d", i.cost+Graph[i.node][j].cost*(Graph[i.node][j].node>i.node?1:-1)); return;}
            Check[Graph[i.node][j].node]=true;
            Q.push(make_str(Graph[i.node][j].node, i.cost+Graph[i.node][j].cost*(Graph[i.node][j].node>i.node?1:-1)));
        }
    }
    return;
}
int Parse(){
    int nr=0; ++k;
    while(C[k]!=' ' && C[k]!='\n') {nr=nr*10+(C[k]-'0'); ++k;}
    return nr;
}
