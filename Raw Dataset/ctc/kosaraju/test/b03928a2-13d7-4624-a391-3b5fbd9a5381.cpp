#include<cstdio>
#include<vector>

using namespace std;

vector<int>g[100000 + 1], scc[100000 + 1];
int visitedTime[100000 + 1], lowTime[100000 + 1], st[100000 + 1], n, m, time, numSCC, vf;
bool onStack[100000 + 1];

inline int minim(int x, int y) {
    if(x <= y) return x;
    return y;
}

void readGraph() {
    int x, y;
    FILE* fin = fopen("ctc.in","r");
    fscanf(fin,"%d%d",&n,&m);
    for(int i = 0; i < m; i++) {
        fscanf(fin,"%d%d",&x,&y);
        g[x].push_back(y);
    }
    fclose(fin);
}

void DFS(int node) {
    vector<int>::iterator it;
    visitedTime[node] = lowTime[node] = ++time;
    st[++vf] = node;
    onStack[node] = true;
    for(it = g[node].begin(); it != g[node].end(); it++) {
        if(visitedTime[*it] == 0) {
            DFS(*it);
            lowTime[node] = minim(lowTime[node],lowTime[*it]);
        } else if(onStack[*it])
            lowTime[node] = minim(lowTime[node],lowTime[*it]);
    }
    if(visitedTime[node] == lowTime[node]) {
        do {
            scc[numSCC].push_back(st[vf]);
            onStack[st[vf]] = false;
            vf--;
        }while(st[vf+1] != node);
        numSCC++;
    }
}

void DFS_master() {
    for(int i = 1; i <= n; i++)
        if(visitedTime[i] == 0)
            DFS(i);
}

void printSCC() {
    int i, j, k;
    FILE* fout = fopen("ctc.out","w");
    fprintf(fout,"%d\n",numSCC);
    for(i = 0; i < numSCC; i++) {
        k = scc[i].size();
        for(j = 0; j < k; j++)
            fprintf(fout,"%d ",scc[i][j]);
        fprintf(fout,"\n");
    }
    fclose(fout);
}

int main() {
    readGraph();
    DFS_master();
    printSCC();
    return 0;
}
