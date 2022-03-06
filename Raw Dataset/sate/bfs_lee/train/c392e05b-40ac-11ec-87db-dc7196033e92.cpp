#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
using namespace std;

ifstream f("sate.in");
ofstream g("sate.out");

vector<pair<int, int>> muchiile_din[30001];
bool vizitat[30001];
int distanta[30001];
queue<int> parcurs;
int n, m, x, y;

void citire() {
    f>>n>>m>>x>>y;

    int a, b, c;
    for(int i=0; i<m; i++) {
        f>>a>>b>>c;
        muchiile_din[a].push_back(make_pair(b,c));
        muchiile_din[b].push_back(make_pair(a,-c));
    }
}

int BFS() {
    int i;
    parcurs.push(x);
    vizitat[x] = true;

    while(!parcurs.empty()) {
        i = parcurs.front();
        parcurs.pop();

        for(auto j : muchiile_din[i])
            if(!vizitat[j.first]) {

                parcurs.push(j.first);

                vizitat[j.first] = true;
                distanta[j.first] = distanta[i] + j.second;

                if(j.first == y)
                    return distanta[j.first];
            }
    }
}

int main() {
    citire();
    f.close();
    g<<BFS();
    g.close();
}
