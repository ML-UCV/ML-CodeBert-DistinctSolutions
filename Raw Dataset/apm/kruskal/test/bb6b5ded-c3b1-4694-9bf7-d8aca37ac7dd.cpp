#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>




using namespace std;



ifstream in("apm.in");

ofstream out("apm.out");



int n, m, nRasp, costRasp, tati[400001], rang[400001];

pair<int, int> rasp[400001];



struct muchie {

    int x, y, cost;

} muchii[400001];



bool compara(muchie a, muchie b) {

    return a.cost < b.cost;

}



int verTati(int Nod) {

    while (tati[Nod] != Nod)

        Nod = tati[Nod];



    return Nod;

}



void uneste(int x, int y) {

    if (rang[x] < rang[y])

        tati[x] = y;

    else if (rang[y] < rang[x])

        tati[y] = x;

    else {

        tati[y] = x;

        ++rang[x];

    }

}



int main() {

    in >> n >> m;

    for (int i = 1; i <= n; ++i) {

        tati[i] = i;

        rang[i] = 1;

    }



    for (int i = 1; i <= m; ++i)

        in >> muchii[i].x >> muchii[i].y >> muchii[i].cost;

    sort(muchii + 1, muchii + m + 1, compara);



    for (int i = 1; i <= m; ++i) {

        int a = verTati(muchii[i].x);

        int b = verTati(muchii[i].y);



        if (a != b) {

            uneste(a, b);

            rasp[++nRasp].first = muchii[i].x;

            rasp[nRasp].second = muchii[i].y;

            costRasp += muchii[i].cost;

        }

    }



    out << costRasp << '\n' << n - 1 << '\n';

    for (int i = 1; i <= nRasp; ++i)

        out << rasp[i].first << ' ' << rasp[i].second << '\n';

    return 0;

}
