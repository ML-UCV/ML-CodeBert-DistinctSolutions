#include <bits/stdc++.h>
using namespace std;

ifstream fin("sate.in");
ofstream fout("sate.out");

int n,m,x,y;
int NOD1,NOD2;
vector < int > noduri[30005];
vector < int > dt[30005];
int vizitat[30005];
int distanta[30005];
int distnc;

void graf(int NOD, int distnc) {

    distanta[NOD]= distnc;
    vizitat[NOD]=1;

    for (int i=0;i<noduri[NOD].size();i++) {

        int nodtoviz = noduri[NOD][i];
        if (vizitat[nodtoviz]==0) {
            if (nodtoviz<NOD) {
                graf(nodtoviz,distnc-dt[NOD][i]);
            }
            else {
                graf(nodtoviz,distnc+dt[NOD][i]);
            }
        }
    }
}

int main()
{
    fin >> n;
    fin>> m;
    fin >> NOD1;
    fin >> NOD2;

    for (int i=1;i<=m;i++) {
        fin >> x >> y >> distnc;
        noduri[x].push_back(y);
        noduri[y].push_back(x);
        dt[x].push_back(distnc);
        dt[y].push_back(distnc);
    }
    graf(NOD1,0);
    fout << distanta[NOD2];
    return 0;
}
