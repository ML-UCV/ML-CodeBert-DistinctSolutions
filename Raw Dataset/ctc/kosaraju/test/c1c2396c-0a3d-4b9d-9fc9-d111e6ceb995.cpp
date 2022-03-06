#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <map>
#include <cstring>

using namespace std;

const int MX = 100001;
vector<int> graf[MX];
vector<int> grafReverse[MX];
stack<int> parcurgereInversa;
int vizite[MX];
map<int, vector<int>> harta;
int counter;
int n, m;

void parcurgereDFS(int poz) {
    vizite[poz] = 1;
    for (auto &vecin : graf[poz]) {
        if (vizite[vecin] == 0)
            parcurgereDFS(vecin);
    }
    parcurgereInversa.push(poz);
}

void parcurgereDFSReverse(int poz) {
    vizite[poz] = counter;
    harta[counter].emplace_back(poz);

    for (auto &vecin : grafReverse[poz]) {
        if (vizite[vecin] == 0)
            parcurgereDFSReverse(vecin);
    }
}

void parcurgereDFSR() {

    while (parcurgereInversa.empty() == 0) {
        int poz = parcurgereInversa.top();
        if (vizite[poz] == 0) {
            harta.insert(pair<int, vector<int>>(counter, vector<int>{}));
            counter++;
            parcurgereDFSReverse(poz);
        }
        parcurgereInversa.pop();
    }
}

ifstream f("ctc.in");
ofstream g("ctc.out");

int main() {
    f >> n >> m;
    for (int i = 0; i < m; i++) {
        int sursa, destinatie;
        f >> sursa >> destinatie;
        graf[sursa].emplace_back(destinatie);
        grafReverse[destinatie].emplace_back(sursa);
    }

    for (int i = 1; i <= n; i++)
        if (vizite[i] == 0)
            parcurgereDFS(i);

    memset(vizite, 0, (n + 1) * sizeof(int));

    parcurgereDFSR();

    g << counter << '\n';

    for (int i = 1; i <= counter; i++) {
        for (unsigned int j = 0; j < harta[i].size(); j++)
            g << harta[i][j] << ' ';
        g << '\n';
    }
    f.close();
    g.close();
    return 0;
}
