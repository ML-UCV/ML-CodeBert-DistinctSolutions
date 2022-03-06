#include <iostream>
#include <vector>
#include <fstream>
#include <stack>
#include <climits>

using namespace std;

struct nod {
    int ind;
    int lowlink;
    bool inStiva;

    nod(int i, int l) {
        this->ind = i;
        this->lowlink = l;
        this->inStiva = false;
    }
};


ifstream f("ctc.in");
ofstream g("ctc.out");


vector<nod> noduri;
vector<int> vecin[100000];

int n, m, index;
stack<int> S;
vector<vector<int>> output;

void citire() {
    f >> n >> m;
    for (int i = 0; i < n; ++i) {
        noduri.emplace_back(INT_MIN, INT_MAX);
    }
    for (int i = 0; i < m; ++i) {
        int x, y;
        f >> x >> y;
        x--, y--;
        vecin[x].push_back(y);
    }
}

void afisare() {
    g << output.size() << '\n';
    for (auto it : output) {
        for (auto it2 : it) {
            g << it2 << ' ';
        }
        g << "\n";
    }
}

void tarjaaaaan(int z) {
    noduri[z].ind = index;
    noduri[z].lowlink = index;
    index++;
    S.push(z);
    noduri[z].inStiva = true;
    for (auto it : vecin[z]) {
        if (noduri[it].ind == INT_MIN) {
            tarjaaaaan(it);
            noduri[z].lowlink = min(noduri[z].lowlink, noduri[it].lowlink);
        } else if (noduri[it].inStiva) {
            noduri[z].lowlink = min(noduri[z].lowlink, noduri[it].ind);
        }
    }
    if (noduri[z].lowlink == noduri[z].ind) {
        vector<int> comp;
        int w;
        do {
            w = S.top();
            S.pop();
            noduri[w].inStiva = false;
            comp.push_back(w + 1);
        } while (w != z);
        output.push_back(comp);
    }
}

int main() {
    citire();

    for (int i = 0; i < n; ++i) {
        if (noduri[i].ind == INT_MIN) {
            tarjaaaaan(i);
        }
    }

    afisare();
    return 0;
}
