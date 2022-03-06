#include <fstream>
#include <vector>
#include <bitset>
#include <cstring>
#define f in
#define g out
#define sat first
#define dist second

using namespace std;
ifstream in ( "sate.in" );
ofstream out( "sate.out" );
vector< pair <int, int> > L[30010];
int n, m, i, j, start, finish, x, y, cost, p, u, vecin, nod;
bitset<30030>fr;
int v[30009], d[30009];
char s[50];

int main() {
    f>>n>>m>>start>>finish; f.get();
    for ( ; m--; ){
        f.getline(s, 30);
        
        i = 0; x = 0;
        while ( s[i] != ' ' )
            x = x*10 + s[i++] - '0';
        
        i++; y = 0;
        while ( s[i] != ' ' )
            y = y*10 + s[i++] - '0';
        
        i++; cost = 0;
        while ( isdigit(s[i]) )
            cost = cost*10 + s[i++] - '0';
        
        L[x].push_back({y, cost});
        L[y].push_back({x, -cost});
    }
    p = u = 1;
    v[1] = start;
    while ( p <= u ){
        nod = v[p];
        for ( i=0; i < L[nod].size(); ++i ){
            vecin = L[nod][i].sat;
            cost = L[nod][i].dist;
            if ( !fr[vecin] ){
                fr[vecin] = 1;
                d[vecin] = d[nod]+cost;
                v[++u] = vecin;
                if ( vecin == finish ){
                    g<<d[vecin];
                    return 0;
                }
            }
        }
        ++p;
    }
    return 0;
}

