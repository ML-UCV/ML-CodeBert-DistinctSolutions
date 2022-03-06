#include <fstream>
#include <iomanip>
#include <string>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>
#include <set>
#include <map>
#include <string.h>
#include <queue>
#include <stack>

#define INF 0x3f3f3f3f

using namespace std;

#ifdef DEBUG
string name = "data";
#else
string name = "sate";
#endif

ifstream fin(name + ".in");
ofstream fout(name + ".out");

int n, m;

int s, t;

#define MAXN 30005

struct Edge {
    int to;
    int weight;
};

vector<Edge> g[MAXN];
int d[MAXN];
bool viz[MAXN];

int k = 0;

int nextNumber(string &s) {
    while (s[k] == ' ' || s[k] == '\n') {
        k++;
    }
    
    int rez = 0;
    
    while (s[k] >= '0' && s[k] <= '9') {
        rez *= 10;
        rez += s[k] - '0';
        k++;
    }
    
    return rez;
}


int main() {
    
    fin >> n >> m >> s >> t;
    
    string ss((istreambuf_iterator<char>(fin)), (istreambuf_iterator<char>()));
    
    for (int i = 0; i < m; ++i) {
        int x,y,w;
        x = nextNumber(ss);
        y = nextNumber(ss);
        w = nextNumber(ss);
        g[x].push_back({y, w});
        g[y].push_back({x, -w});
    }
    
    queue<int> q;
    
    q.push(s);
    viz[s] = true;
    
    while (true) {
        auto node = q.front();
        q.pop();
        
        for (auto edge: g[node]) {
            if (viz[edge.to]) {
                continue;
            }
            
            viz[edge.to] = true;
            d[edge.to] = d[node] + edge.weight;
            q.push(edge.to);
            if (edge.to == t) {
                fout << d[edge.to];
                return 0;
            }
        }

    }
    
    return 0;
}
