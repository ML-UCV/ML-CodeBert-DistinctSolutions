#include <fstream>
#include <vector>
#include <queue>
#include <utility>
#include <cstring>

using namespace std;

ofstream fout("sate.out");

const int NMax = 30000, BufferSize = 100000;

vector < pair<int, int> > G[NMax + 5]; queue <int> Q;
int D[NMax + 5], N, M, X, Y, pos;

char B[BufferSize + 5];

int Parse() {
    int Value = 0;

    while(B[pos] < '0' || B[pos] > '9') {
        pos++;
        if(pos == BufferSize) {
            fread(B, BufferSize, 1, stdin);
            pos = 0;
        }
    }

    while(B[pos] >= '0' && B[pos] <= '9') {
        Value = Value * 10 + (B[pos] - '0');

        pos++;
        if(pos == BufferSize) {
            fread(B, BufferSize, 1, stdin);
            pos = 0;
        }
    }
    return Value;
}

void Read() {
    freopen("sate.in", "r", stdin);
    fread(B, BufferSize, 1, stdin);

    N = Parse(), M = Parse();
    X = Parse(), Y = Parse();
    if(X > Y) swap(X, Y);

    for(int i = 1, a, b, c; i <= M; i++)
    {
        a = Parse(), b = Parse(), c = Parse();

        G[a].push_back({b,  c});
        G[b].push_back({a, -c});
    }
    for(int i = 1; i <= N; i++)
        D[i] = -1;
}

void BFS(int Nod) {
    Q.push(Nod), D[Nod] = 0;

    while(!Q.empty()) {
         Nod = Q.front(); Q.pop();

         for(auto Vecin : G[Nod])
         {
             if(D[Vecin.first] == -1)
                D[Vecin.first] = D[Nod] + Vecin.second, Q.push(Vecin.first);

            if(D[Y] != -1) return;
         }
    }
}

int main()
{
    Read(); BFS(X);
    fout << D[Y] << '\n';

    fout.close();

    return 0;
}
