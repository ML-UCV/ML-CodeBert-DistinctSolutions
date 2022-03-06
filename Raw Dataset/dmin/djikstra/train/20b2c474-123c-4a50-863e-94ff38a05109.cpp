#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <bitset>
#include <cmath>
using namespace std;



ifstream fin ("dmin.in");

ofstream fout ("dmin.out");



const int maxn = 15005;

const int mod = 104659;

const double eps = 1e-8;

const double oo = 1e40;

vector <pair<int,double> > G[maxn];

double Dist[maxn];

int Cnt[maxn];



void Dijkstra(int start, int n) {

    vector < pair <int,double> > :: iterator it;

    priority_queue <pair <double,int> > H;

    bitset <maxn> Vis = 0;

    int node, i;

    for (i = 1; i <= n; i++) {

        Dist[i] = oo;

    }

    Dist[start] = 0;

    Cnt[start] = 1;

    H.push(make_pair(0, start));

    while (!H.empty()) {

        node = H.top().second;

        H.pop();

        if (Vis[node] == true) {

            continue;

        }

        Vis[node] = true;

        for (it = G[node].begin(); it != G[node].end(); it++) {

            if (Dist[it->first] - eps > Dist[node] + it->second) {

                Dist[it->first] = Dist[node] + it->second;

                Cnt[it->first] = Cnt[node];

                H.push(make_pair(-Dist[it->first], it->first));

            } else if (Dist[it->first] + eps > Dist[node] + it->second) {

                Cnt[it->first] += Cnt[node];

                if (Cnt[it->first] >= mod) {

                    Cnt[it->first] -= mod;

                }

            }

        }

    }

}



int main() {

    ios_base :: sync_with_stdio (false);

    int n, m, x, y, c, i;

    fin >> n >> m;

    for (i = 1; i <= m; i++) {

        fin >> x >> y >> c;

        G[x].push_back(make_pair(y, log(c)));

        G[y].push_back(make_pair(x, log(c)));

    }

    Dijkstra(1, n);

    for (i = 2; i <= n; i++) {

        fout << Cnt[i] << " ";

    }

    fin.close();

    fout.close();

    return 0;

}
