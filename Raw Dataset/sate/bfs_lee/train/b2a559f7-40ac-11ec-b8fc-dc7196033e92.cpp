#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
#define debug(v,n) for (int i = 1; i <= (n); ++i) cout << v[i] << " ";
#define next cout << '\n'
using namespace std;

const int N = 30005;
vector<pair<int,int>> graf[N];
int n, m, x, y;
bool amfost[N];
queue<pair<int,int>> coada;

int main() {
    //ifstream fin("date.in.txt");
    ifstream fin("sate.in");
    ofstream fout("sate.out");
    fin >> n >> m >> x >> y;

    if(x > y)
        swap(x,y);

    for (int i = 1; i <= m; ++i) {
        int a, b, d;
        fin >> a >> b >> d;
        graf[a].push_back({b, d});
        graf[b].push_back({a, d});
    }
    for (pair<int,int> i : graf[x]) {
        int to = i.first, d = i.second;
        if(to < x) {
            coada.push({to, -d});
            amfost[to] = true;
        }
        else {
            coada.push({to, d});
            amfost[to] = true;
        }
    }
    while(!coada.empty()) {
        int nod = coada.front().first;
        int act = coada.front().second;
        coada.pop();

        if(nod == y) {
            fout << act;
            return 0;
        }

        for (pair<int,int> i : graf[nod]) {
            int to = i.first, d = i.second;
            if (to < nod && amfost[to] == false) {
                coada.push({to, act - d});
                amfost[to] = true;
            }
            else if (to > nod && amfost[to] == false) {
                coada.push({to, act + d});
                amfost[to] = true;
            }
        }
    }
    return 0;
}
