#include <iostream>
#include <fstream>
#include <algorithm>


using namespace std;



ifstream in("apm.in");

ofstream out("apm.out");



const int MAX = 400005;



struct muchie {

    int x, y, c;

} muchii[MAX];



int n, m, total, TT[MAX], RG[MAX], k;



bool compare(muchie a, muchie b) {

    return a.c < b.c;

}



pair <int, int> P[MAX];



void citire() {

    in >> n >> m;

    int x, y, c;

    for(int i = 1; i <= m; i++) {

        in >> x >> y >> c;

        muchii[i].x = x;

        muchii[i].y = y;

        muchii[i].c = c;

    }

    sort(muchii + 1, muchii + m + 1, compare);

}



int Find(int nod) {

    while(TT[nod] != nod)

        nod = TT[nod];

    return nod;

}



void Unite(int x, int y) {

    if(RG[x] < RG[y])

        TT[x] = y;

    if(RG[y] < RG[x])

        TT[y] = x;

    if(RG[x] == RG[y]) {

        TT[x] = y;

        RG[y]++;

    }

}



void Solve() {

    for(int i = 1; i <= m; i++) {

        int tata_x = Find(muchii[i].x);

        int tata_y = Find(muchii[i].y);

        if(tata_x != tata_y) {

            Unite(tata_x, tata_y);

            P[++k].first = muchii[i].x;

            P[k].second = muchii[i].y;

            total += muchii[i].c;

        }

    }

}



int main() {

    citire();



    for(int i = 1; i <= m; i++) {

        TT[i] = i;

        RG[i] = 1;

    }



    Solve();



    out << total << "\n";

    out << n - 1 << "\n";



    for(int i = 1; i <= k; i++) {

        out << P[i].first << " " << P[i].second << " " << "\n";

    }

    return 0;

}
