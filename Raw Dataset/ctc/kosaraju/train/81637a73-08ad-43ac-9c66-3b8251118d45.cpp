#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <queue>
#include <bitset>
#include <stack>
#include <cmath>
#include <stdio.h>
#include <string.h>



using namespace std;

ifstream in("ctc.in");
ofstream out("ctc.out");

int n, m, soll;
int used[100008];
vector<int> g1[100008],g2[100008],sol[100008];
stack<int> s;

void dfs(int nod){
    used[nod] = 1;
    for(int i = 0; i < g1[nod].size(); i++)
        if(!used[g1[nod][i]])
            dfs(g1[nod][i]);
    s.push(nod);
}
void dfs2(int nod, int nr){
    sol[nr].push_back(nod);
    used[nod] = 1;
    for(int i = 0; i < g2[nod].size(); i++)
        if(!used[g2[nod][i]])
            dfs2(g2[nod][i], nr);
}

void Kosarju(){
    for(int i = 1; i <= n; i++)
        if(!used[i])
            dfs(i);

    memset(used,0,sizeof(used));

    for(int i = 1; i <= n; i++){
        if(!used[s.top()]){
            soll++;
            dfs2(s.top(),soll);
        }
        s.pop();
    }
    out << soll <<'\n';
    for(int i = 1; i <= soll; i++){
        for(int j = 0; j < sol[i].size(); j++)
            out << sol[i][j] <<" ";
        out << '\n';
    }
}

int main(){
    in >> n >> m;
    for(int i = 1; i <= m; i++){
        int x, y;
        in >> x >> y;
        g1[x].push_back(y);
        g2[y].push_back(x);
    }
    Kosarju();
    return 0;
}
