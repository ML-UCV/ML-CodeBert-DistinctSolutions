#include <iostream>
#include <fstream>
#include <vector>
#include <bitset>
#include <stack>
using namespace std;
ofstream fout("sate.out");
int n, m, x, y;
vector<pair<int, int> > nod[30001];
int dist[30001];
bitset<30001> haveDist;

/// parsare
FILE* fin = fopen("sate.in","r");
const unsigned maxb=100192;
char buf[maxb];
unsigned ptr=maxb;

inline unsigned getInt(){
    unsigned nr=0;
    while(buf[ptr]<'0'||'9'<buf[ptr])
    if(++ptr>=maxb)
        fread(buf,maxb,1,fin),ptr=0;
    while('0'<=buf[ptr]&&buf[ptr]<='9'){
        nr=nr*10+buf[ptr]-'0';
        if(++ptr>=maxb)
            fread(buf,maxb,1,fin),ptr=0;
    }
    return nr;
}

void readAndSet() {
    n = getInt();
    m = getInt();
    x = getInt();
    y = getInt();

    for (int i = 1; i <= m; i++) {
        int a = getInt();
        int b = getInt();
        int cost = getInt();

        nod[a].push_back(make_pair(b, cost));
        nod[b].push_back(make_pair(a, -cost));
    }
}

void genDistance() {
    stack<int> s;

    s.push(x);
    haveDist[x] = true;

    while (!s.empty()) {
        int i = s.top();
        s.pop();

        if (haveDist[y])
            break;

        for (pair<int, int> way : nod[i])
            if (!haveDist[way.first]) {
                haveDist[way.first] = true;
                dist[way.first] = dist[i] + way.second;

                s.push(way.first);
            }
    }
}

int main() {
    readAndSet();
    genDistance();

    fout << dist[y] - dist[x];
    return 0;
}
