#include <vector>
#include <iostream>
#include <fstream>
#include <stack>
#include <string.h>


using namespace std;



ifstream f("ctc.in");

ofstream g("ctc.out");



vector <int> graf1[100001], graf2[100001], componente[100001];

int vizitat[100001], nr, n, m;

stack<int> s;



void citire() {

    int x, y;

    f >> n >> m;

    for(int i = 1; i <= m; i++) {

        f >> x >> y;

        graf1[x].push_back(y);

        graf2[y].push_back(x);

    }

}



int DFS1(int nod) {

    vizitat[nod] = 1;

    for(int i=0; i < graf1[nod].size(); i++)

        if(vizitat[graf1[nod][i]] == 0)

            DFS1(graf1[nod][i]);

    s.push(nod);

}



int DFS2(int nod) {

    vizitat[nod] = 1;

    componente[nr].push_back(nod);

    for(int i=0; i < graf2[nod].size(); i++)

        if(vizitat[graf2[nod][i]] == 0)

            DFS2(graf2[nod][i]);

}



void afisare() {

    g << nr << "\n";

    for(int i = 1; i <= nr; i++) {

        for(int j = 0; j < componente[i].size(); j++)

            g << componente[i][j] <<" ";

        g << "\n";

    }

}



int main() {

    citire();

    for(int i = 1; i <= n; i++)

        if(vizitat[i] == 0)

            DFS1(i);

    memset(vizitat, 0, sizeof(vizitat));

    while(s.empty() == 0) {

        if(vizitat[s.top()] == 0) {

            nr++;

            DFS2(s.top());

        }

        s.pop();

    }

    afisare();

    return 0;

}
