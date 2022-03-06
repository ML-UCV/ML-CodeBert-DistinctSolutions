#include <iostream>
#include<fstream>
#include<queue>
#include<algorithm>
#include<vector>
#define vecin first
#define dist second
using namespace std;

ofstream out("sate.out");

const int nmax = 30005;
const int mmax = 100050;
int n, m, x, y, d[nmax];
vector<pair<int, int> > graf[nmax];
queue<int> q;

int BFS_x_to_y(int start, int finnish ){

    int nod_curent;
    q.push(start);
    d[start] = 0;

    while(!q.empty()){
        nod_curent = q.front();
        q.pop();

        if(nod_curent == finnish){
            return d[finnish];
        }

        for(int i = 0; i < graf[nod_curent].size(); ++i){
            int v = graf[nod_curent][i].vecin;
            int k = graf[nod_curent][i].dist;
            if(d[v] == 0 && v != 1){
                q.push(v);
                if( v < nod_curent ) d[v] = d[nod_curent] - k;
                else d[v] = d[nod_curent] + k;
            }
        }
    }
}

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

void readAndSet(){
    n = getInt();
    m = getInt();
    x = getInt();
    y = getInt();

    for(int i = 1; i <= m; ++i){
        int a = getInt();
        int b = getInt();
        int c = getInt();

        graf[a].push_back( make_pair(b, c) );
        graf[b].push_back( make_pair(a, c) );
    }
}

int main()
{

    readAndSet();
    out<<BFS_x_to_y(x, y);

    out.close();
    return 0;
}
