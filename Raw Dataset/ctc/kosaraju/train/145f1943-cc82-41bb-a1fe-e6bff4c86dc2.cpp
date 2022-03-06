#include <iostream>
#include <fstream>
#include <vector>
#include <stack>

using namespace std;

ifstream f("ctc.in");
ofstream g("ctc.out");

const int NMAX = 100'001;

int n,m, beenThere[NMAX], strongly_conn;
vector <int> G[NMAX] , GT[NMAX] , sol[NMAX];
stack <int> s;

void Read() {

    f >> n >> m;

    while(m--) {
        int x, y;
        f >> x >> y;
        G[x].push_back(y);
        GT[y].push_back(x);
    }
}

void dfs(int node) {

    beenThere[node] = 1;

    for(int neighbor : G[node])
        if(!beenThere[neighbor])
            dfs(neighbor);

    s.push(node);
}

void dfsReverse(int node) {

    beenThere[node] = 1;
    sol[strongly_conn].push_back(node);

    for(int neighbor : GT[node])
        if(!beenThere[neighbor])
            dfsReverse(neighbor);
}

void kosaraju() {

    for(int i = 1;i <= n;++i)
        if(!beenThere[i])
            dfs(i);

    for(int i = 1;i <= n;++i)
        beenThere[i] = 0;

    while(!s.empty()) {
        int node = s.top();
        if(beenThere[node] == 0) {
            strongly_conn++;
            dfsReverse(node);
        }
        s.pop();
    }
}

void print() {

    g << strongly_conn << '\n';

    for(int i = 1;i <= strongly_conn;++i,g << '\n')
        for(int node : sol[i])
            g << node << ' ';
}

int main() {

    Read();
    kosaraju();
    print();

    return 0;
}
