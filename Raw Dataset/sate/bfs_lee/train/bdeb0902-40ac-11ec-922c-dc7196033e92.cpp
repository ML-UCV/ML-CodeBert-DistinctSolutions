#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
using namespace std;

int n, m, sursa, destinatie;
const int MX = 30001;

int distante[MX];
vector< pair<int, int> > graf[MX];
int vizitat[MX];
queue<int> deViz;

void parcurgereBFS(int sursa) {
    for (auto satVecinSiD : graf[sursa])
        if (vizitat[satVecinSiD.first] == 0) {
            int vecin = satVecinSiD.first;
            if (vecin < sursa)
                distante[vecin] = distante[sursa] - satVecinSiD.second;
            else if (vecin > sursa)
                distante[vecin] = distante[sursa] + satVecinSiD.second;
            vizitat[vecin] = 1;
            deViz.push(vecin);
        }
}

ifstream f("sate.in");
ofstream g("sate.out");

int main() {
    f >> n >> m >> sursa >> destinatie;
    for (int i = 1; i <= m; i++){
        int a, b, dist;
        f >> a >> b >> dist;
        graf[a].emplace_back(make_pair(b, dist));
        graf[b].emplace_back(make_pair(a, dist));
    }

    deViz.push(sursa);
    while (deViz.empty() == 0) {
        int nod = deViz.front();
        parcurgereBFS(nod);
        deViz.pop();
    }

    g << distante[destinatie];

    f.close();
    g.close();
    return 0;
}
