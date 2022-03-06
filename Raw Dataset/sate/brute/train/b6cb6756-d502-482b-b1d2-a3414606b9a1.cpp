#include<bits/stdc++.h>
#define pb push_back
#define MAXN 30005
using namespace std;

ifstream fin("sate.in");
ofstream fout("sate.out");

int verific[MAXN], sate, distante, start, stop, total;
vector<pair<int,int>> urmatorul_sat[MAXN];

void calculeaza_distanta(int sat, int distanta) {
   verific[sat] = 1;
   if (sat == stop) 
       total = distanta;
   if (total) 
       return;
   for (auto urmatorul : urmatorul_sat[sat]) 
        if (!verific[urmatorul.first]) 
            calculeaza_distanta(urmatorul.first, distanta + urmatorul.second);
}

int main() {
    fin >> sate >> distante >> start >> stop;
    int x, y, c;
    while (distante--) {
        fin >> x >> y >> c;
        urmatorul_sat[x].pb(make_pair(y, c));
        urmatorul_sat[y].pb(make_pair(x, c * -1));
    }
    calculeaza_distanta(start, 0);
    fout << total;
}
