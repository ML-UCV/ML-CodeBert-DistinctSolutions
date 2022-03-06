#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <cmath>
#include <bitset>

using namespace std;

const int Nmax = 1501;
const double eps = 0.0000001;
const int modulo = 104659;

vector <int> numar(Nmax);
vector <double> dist(Nmax);
bitset <Nmax> viz;
vector< pair<int,double> > Graf[Nmax];
queue <int> Q;

int N, M;

void citire(){

    ifstream f("dmin.in");

    f >> N >> M;

    int a, b;
    double c;

    for(; M; M--) {

        f >> a >> b >> c;
        c = log(c);

        Graf[a].push_back(pair<int, double>(b, c));
        Graf[b].push_back(pair<int, double>(a, c));
    }
}


void dijkstra() {

    vector< pair<int, double> >::iterator it;

    for(int i = 1; i <= N; ++i)
        dist[i] = 9999999.0;

    Q.push(1);
    dist[1] = 0;
    numar[1] = 1;
    viz[1] = 1;

    while(!Q.empty()){

        int nod = Q.front();
        Q.pop();

        for(it = Graf[nod].begin(); it != Graf[nod].end(); ++it){

            if(dist[it->first] - dist[nod] - it->second > eps){

                dist[it->first] = dist[nod] + it->second;
                numar[it->first] = numar[nod];

                if(!viz[it->first]){

                    viz[it->first] = 1;
                    Q.push(it->first);
                }
            }
            else
                if(dist[nod] + it->second - dist[it->first] <= eps){

                    numar[it->first] += numar[nod];
                    numar[it->first] %= modulo;
            }
        }
    }
}

void afis(){

    ofstream g("dmin.out");

    for(int i = 2; i <= N; ++i)
        g << numar[i] << " ";
}

int main() {

    citire();
    dijkstra();
    afis();

    return 0;
}
