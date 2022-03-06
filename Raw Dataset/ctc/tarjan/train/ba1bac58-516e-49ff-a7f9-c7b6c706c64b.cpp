#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

const int NMAX = 1e5;



vector <int> g[1 + NMAX];
vector <int> rasp[1 + NMAX];
int n, m;

void citire() {
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i ++) {
        int u, v;
        scanf("%d%d", &u, &v);

        g[u].push_back(v);
    }
}



int nrComponenteConexte, idCurent;
int lowLink[1 + NMAX], nodeID[1 + NMAX];
bool visited[1 + NMAX], onStack[1 + NMAX];
stack <int> myStack;

void TarjanDFS(int from) {
    visited[from] = true;
    onStack[from] = true;
    myStack.push(from);
    lowLink[from] = nodeID[from] = ++idCurent;

    for(auto &to : g[from]) {
        if(visited[to] == false) {
            TarjanDFS(to);
        }
        if(onStack[to] == true) {
            lowLink[from] = min(lowLink[from], lowLink[to]);
        }
    }

    if(lowLink[from] == nodeID[from]) {

        while(!myStack.empty() && myStack.top() != from) {
            lowLink[myStack.top()] = from;
            rasp[nrComponenteConexte].push_back(myStack.top());

            onStack[myStack.top()] = false;
            myStack.pop();
        }
        rasp[nrComponenteConexte].push_back(myStack.top());
        onStack[myStack.top()] = false;
        myStack.pop();

        nrComponenteConexte ++;
    }
}

void TarjanSSC() {
    for(int i = 1; i <= n; i ++) {
        if(visited[i] == false) {
            TarjanDFS(i);
        }
    }
}



void afisare() {
    printf("%d\n", nrComponenteConexte);
    for(int i = 0; i < nrComponenteConexte; i ++) {
        for(auto &nod: rasp[i]) {
            printf("%d ", nod);
        }
        printf("\n");
    }
}

int main() {
    freopen("ctc.in", "r", stdin);
    freopen("ctc.out", "w", stdout);

    citire();
    TarjanSSC();
    afisare();

    return 0;
}
