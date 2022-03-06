#include <fstream>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;
ifstream fin("ctc.in");
ofstream fout("ctc.out");
int N, M, nr_ctc;
vector<vector<int>> gr, grt;
vector<bool> passed;
vector<int> ctc[100005];
stack<int> L;
void read() {
    int x, y;
    fin >> N >> M;
    gr.resize(N + 1);
    grt.resize(N + 1);
    for (int i = 0; i < M; ++i) {
        fin >> x >> y;
        gr[x].push_back(y);
        grt[y].push_back(x);
    }
}
void normalDfs(int nod) {
    passed[nod] = true;
    for (int i : gr[nod]) {
        if (passed[i] == false) {
            normalDfs(i);
        }
    }
    L.push(nod);
}
void inverseDfs(int nod) {
    ctc[nr_ctc].push_back(nod);
    passed[nod] = true;
    for (int i : grt[nod]) {
        if (passed[i] == false) {
            inverseDfs(i);
        }
    }
}
void print() {
    fout << nr_ctc << "\n";
    for (int i = 0; i < nr_ctc; ++i) {
        for (int j = 0; j < ctc[i].size(); ++j) {
            fout << ctc[i][j] << " ";
        }
        fout << "\n";
    }
}
int main()
{
    read();
    passed.resize(N + 1, false);
    for (int i = 1; i <= N; ++i) {
        if (passed[i] == false) {
            normalDfs(i);
        }
    }
    passed.clear();
    passed.resize(N + 1, false);
    int node;
    while (!L.empty()) {
        node = L.top();
        if (passed[node] == false) {
            inverseDfs(node);
            nr_ctc++;
        }
        L.pop();
    }
    print();
    return 0;
}
